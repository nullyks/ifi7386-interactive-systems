// STEP 2 ONLY: add Wi-Fi AFTER the RC522 reads real UIDs in Serial Monitor.
// WiFiS3 is the library supplied with the UNO R4 WiFi board package.
#include <WiFiS3.h>

const char WIFI_NAME[] = "IFI7386-G2";
// The Pi hotspot uses OPEN Wi-Fi. No password is needed.
// An IP address is the destination computer's address on our local network.
IPAddress raspberryPiAddress(10, 42, 0, 1);
const int SERVER_PORT = 3000;
unsigned long lastWifiAttempt = 0;
bool wifiAttempted = false;
bool wifiWasConnected = false;

const char* wifiStatusName(int status) {
  switch (status) {
    case WL_NO_MODULE: return "WL_NO_MODULE";
    case WL_IDLE_STATUS: return "WL_IDLE_STATUS";
    case WL_NO_SSID_AVAIL: return "WL_NO_SSID_AVAIL";
    case WL_SCAN_COMPLETED: return "WL_SCAN_COMPLETED";
    case WL_CONNECTED: return "WL_CONNECTED";
    case WL_CONNECT_FAILED: return "WL_CONNECT_FAILED";
    case WL_CONNECTION_LOST: return "WL_CONNECTION_LOST";
    case WL_DISCONNECTED: return "WL_DISCONNECTED";
    default: return "OTHER";
  }
}

void prepareWifi() {
  WiFi.setTimeout(10000); // One begin() call can wait for up to ten seconds.
  Serial.print("Wi-Fi target: ");
  Serial.println(WIFI_NAME);
  Serial.println("Wi-Fi security: OPEN (no password)");
  Serial.print("Wi-Fi firmware: ");
  Serial.println(WiFi.firmwareVersion());
}

bool connectToWifi() {
  int status = WiFi.status();
  if (status != WL_CONNECTED) {
    wifiWasConnected = false;
    // Wait ten seconds AFTER an attempt finishes, even if begin() was slow.
    if (!wifiAttempted || millis() - lastWifiAttempt >= 10000) {
      wifiAttempted = true;
      if (status == WL_NO_MODULE) {
        Serial.println("WIFI_NO_MODULE: check the connectivity firmware.");
      } else {
        Serial.print("Connecting to Wi-Fi: ");
        Serial.println(WIFI_NAME);
        // The one-argument form joins an OPEN network without a password.
        int result = WiFi.begin(WIFI_NAME);
        Serial.print("WiFi.begin result: ");
        Serial.print(wifiStatusName(result));
        Serial.print(" (");
        Serial.print(result);
        Serial.println(")");
      }
      // begin() blocks while connecting. Start the retry timer AFTER that wait.
      lastWifiAttempt = millis();
      status = WiFi.status();
      if (status != WL_CONNECTED) {
        Serial.println("WIFI_NOT_CONNECTED: run the separate wifi_check sketch.");
      }
    }
  }

  if (status == WL_CONNECTED) {
    if (!wifiWasConnected) {
      Serial.println("WIFI_CONNECTED");
      Serial.print("Arduino IP: ");
      Serial.println(WiFi.localIP());
      Serial.print("Signal (dBm): ");
      Serial.println(WiFi.RSSI());
    }
    wifiWasConnected = true;
    return true;
  }
  return false; // Keep reading sensors; a later call will retry.
}

// A function lets us give a name to steps we want to reuse.
// endpoint is the server's destination path; jsonText is the message to send.
// true means the server accepted it; false means sending did not succeed.
bool sendToPi(const char* endpoint, String jsonText) {
  if (!connectToWifi()) {
    return false; // Leave the function now. Try again on a later call.
  }

  WiFiClient connection;
  if (!connection.connect(raspberryPiAddress, SERVER_PORT)) {
    Serial.println("HOST_UNREACHABLE: check the Pi and server.");
    return false;
  }

  // HTTP is a text-based request format. Each println ends one header line.
  connection.print("POST ");
  connection.print(endpoint);
  connection.println(" HTTP/1.1");
  connection.println("Host: 10.42.0.1");
  connection.println("Content-Type: application/json");
  connection.println("Connection: close");
  connection.print("Content-Length: ");
  connection.println(jsonText.length());
  connection.println(); // Empty line separates headers from message body.
  connection.print(jsonText);

  // Do not wait forever if the server fails to answer.
  unsigned long waitStarted = millis();
  while (!connection.available() && connection.connected() &&
         millis() - waitStarted < 1500) {
    delay(2);
  }

  // Read only the first response line, for example: HTTP/1.1 200 OK.
  String responseLine = "";
  while (connection.available()) {
    char character = connection.read();
    if (character == '\n') {
      break; // Stop this loop when we reach the end of the line.
    }
    responseLine += character;
  }
  connection.stop();

  if (responseLine.length() == 0) {
    Serial.println("HTTP_TIMEOUT: no response received.");
    return false;
  }
  Serial.println(responseLine);
  return responseLine.startsWith("HTTP/1.1 200");
}


#include <AMRFID.h>
// RC522 uses SPI: SCK = D13, MOSI = D11, MISO = D12.
// SDA on this module means chip select (SS), not the Arduino SDA pin.
const int READER_SS_PIN = 10;
const int READER_RST_PIN = 9;
AMRFID reader(READER_SS_PIN, READER_RST_PIN);

void startReader() {
  reader.begin();
  // begin() starts SPI and initialises the reader. It returns no success flag.
  // A real UID below is the check that the reader and wiring work.
  Serial.println("READER_INITIALISED: scan a card to check the reader.");
}

// Return a NEW card UID, or empty text if there is no new scan.
String readNewCard() {
  // lerUID is the library's method name; it means "read UID".
  // It returns uppercase hexadecimal text, keeping zeros: byte 4 becomes "04".
  // Empty text ("") means no new card could be read.
  String uidText = reader.lerUID();
  if (uidText.length() > 0) {
    Serial.print("UID: ");
    Serial.println(uidText);
  }
  // AMRFID finishes each read by halting the card. Remove it before rescanning.
  return uidText;
}

String pendingUid = ""; // Latest scan waiting to be delivered.
unsigned long pendingSince = 0;
unsigned long lastSendAttempt = 0;
unsigned long lastHeartbeatTime = 0;

void setup() {
  Serial.begin(115200);
  prepareWifi();
  startReader();
}

void loop() {
  String newUid = readNewCard();
  if (newUid.length() > 0) {
    pendingUid = newUid; // A newer scan replaces an older undelivered one.
    pendingSince = millis();
  }

  // A heartbeat says "the board is still here", even with no visitor scanning.
  if (millis() - lastHeartbeatTime >= 2000) {
    lastHeartbeatTime = millis();
    // AMRFID has no hardware-status result. true means begin() was called.
    // This heartbeat proves the board is online, not that its antenna works.
    String heartbeat = "{\"v\":1,\"ready\":true}";
    sendToPi("/api/reader", heartbeat);
  }

  // Do not display a very old scan after a network outage. Ask for a rescan.
  if (pendingUid.length() > 0 && millis() - pendingSince > 5000) {
    Serial.println("Scan expired. Please scan the ticket again.");
    pendingUid = "";
  }

  // Retry at a limited rate; remove the pending UID only after HTTP success.
  if (pendingUid.length() > 0 && millis() - lastSendAttempt >= 1500) {
    lastSendAttempt = millis();
    String message = "{\"v\":1,\"uid\":\"";
    message += pendingUid;
    message += "\"}";
    Serial.println(message);
    bool accepted = sendToPi("/api/ticket", message);
    if (accepted) {
      pendingUid = "";
    }
  }
}

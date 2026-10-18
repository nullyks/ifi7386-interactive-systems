// STEP 2 ONLY: add Wi-Fi AFTER the sensor works in Serial Monitor.
// WiFiS3 is the library supplied with the UNO R4 WiFi board package.
#include <WiFiS3.h>

const char WIFI_NAME[] = "IFI7386-G2";
const char WIFI_PASSWORD[] = "PrototypeG2!";
// An IP address is the destination computer's address on our local network.
IPAddress raspberryPiAddress(10, 42, 0, 1);
const int SERVER_PORT = 3000;
unsigned long lastWifiAttempt = 0;
bool wifiAttempted = false;

bool connectToWifi() {
  // == asks whether two values are equal. = would assign a value instead.
  if (WiFi.status() == WL_CONNECTED) {
    return true;
  }

  // Retry every 10 seconds. millis() counts milliseconds since board startup.
  if (!wifiAttempted || millis() - lastWifiAttempt >= 10000) {
    wifiAttempted = true;
    lastWifiAttempt = millis();
    Serial.println("Connecting to Wi-Fi...");
    WiFi.begin(WIFI_NAME, WIFI_PASSWORD);
  }
  return WiFi.status() == WL_CONNECTED;
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


#include <Adafruit_PN532.h>
// Software SPI pin order: clock, data IN, data OUT, chip select.
// Check the wiring/voltage guide BEFORE connecting this reader.
Adafruit_PN532 reader(13, 12, 11, 10);
bool readerReady = false;
String previousUid = "";
unsigned long lastCardSeenTime = 0;
unsigned long lastReaderRetryTime = 0;

void startReader() {
  reader.begin();
  // A non-zero version means the chip replied to our request.
  readerReady = reader.getFirmwareVersion() != 0;
  if (readerReady) {
    readerReady = reader.SAMConfig(); // Configure normal card-reading mode.
    reader.setPassiveActivationRetries(1);
  }
  if (readerReady) {
    Serial.println("READER_READY");
  } else {
    Serial.println("READER_NOT_FOUND: check wiring, mode and power.");
  }
}

// Return a NEW card UID, or empty text if there is no new scan.
String readNewCard() {
  if (!readerReady) {
    if (millis() - lastReaderRetryTime >= 5000) {
      lastReaderRetryTime = millis();
      startReader();
    }
    return "";
  }

  // A UID is a sequence of bytes. uint8_t holds one byte (0 through 255).
  uint8_t uidBytes[10]; // Reserve room for up to ten UID bytes.
  uint8_t uidLength = 0;
  bool cardFound = reader.readPassiveTargetID(
    PN532_MIFARE_ISO14443A, uidBytes, &uidLength, 100);
  // & lets the library fill in uidLength. 100 limits the wait to 100 ms.
  if (!cardFound) {
    return "";
  }

  String uidText = "";
  // Start at byte 0; repeat while index is below uidLength; add 1 each time.
  for (int index = 0; index < uidLength; index++) {
    if (uidBytes[index] < 16) {
      uidText += "0"; // Preserve leading zero: byte 4 must become "04".
    }
    uidText += String(uidBytes[index], HEX); // HEX uses base 16, not base 10.
  }
  uidText.toUpperCase();

  // Avoid repeating a held card. Remove it for >2 seconds before rescanning.
  bool isNewScan = false;
  if (uidText != previousUid) {
    isNewScan = true;
  }
  if (millis() - lastCardSeenTime > 1200) {
    isNewScan = true;
  }
  previousUid = uidText;
  lastCardSeenTime = millis();

  if (isNewScan) {
    Serial.print("UID: ");
    Serial.println(uidText);
    return uidText;
  }
  return "";
}

String pendingUid = ""; // Latest scan waiting to be delivered.
unsigned long pendingSince = 0;
unsigned long lastSendAttempt = 0;
unsigned long lastHeartbeatTime = 0;

void setup() {
  Serial.begin(115200);
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
    String heartbeat = "{\"v\":1,\"ready\":";
    if (readerReady) {
      heartbeat += "true";
    } else {
      heartbeat += "false";
    }
    heartbeat += "}";
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

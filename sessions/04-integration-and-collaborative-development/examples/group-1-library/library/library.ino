// STEP 2 ONLY: add Wi-Fi AFTER the sensor works in Serial Monitor.
// WiFiS3 is the library supplied with the UNO R4 WiFi board package.
#include <WiFiS3.h>

const char WIFI_NAME[] = "IFI7386-G1";
const char WIFI_PASSWORD[] = "PrototypeG1!";
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
  Serial.println(WIFI_NAME); // Never print the password.
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
        int result = WiFi.begin(WIFI_NAME, WIFI_PASSWORD);
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


// Each chair gets its OWN pin, measurement, threshold and remembered state.
// int stores a whole number; bool stores either true or false.
const int CHAIR_1_PIN = A0;
const int CHAIR_2_PIN = A1;

// CHANGE THESE after measuring your mounted chairs. These are example values.
const int CHAIR_1_ON = 550;
const int CHAIR_1_OFF = 400;
const int CHAIR_2_ON = 550;
const int CHAIR_2_OFF = 400;

int chair1Reading = 0;
int chair2Reading = 0;
bool chair1Occupied = false;
bool chair2Occupied = false;

void readChairs() {
  // analogRead measures the voltage at a pin as a number from 0 to 1023.
  // Keep 3 parts of the old reading and 1 part of the new reading.
  // This simple average reduces short jumps in the measured values.
  chair1Reading = (chair1Reading * 3 + analogRead(CHAIR_1_PIN)) / 4;
  chair2Reading = (chair2Reading * 3 + analogRead(CHAIR_2_PIN)) / 4;

  // Two thresholds prevent rapid switching near one boundary (hysteresis).
  // Between OFF and ON we leave the previous occupied value unchanged.
  if (chair1Reading > CHAIR_1_ON) {
    chair1Occupied = true;
  } else if (chair1Reading < CHAIR_1_OFF) {
    chair1Occupied = false;
  }

  if (chair2Reading > CHAIR_2_ON) {
    chair2Occupied = true;
  } else if (chair2Reading < CHAIR_2_OFF) {
    chair2Occupied = false;
  }
}

void printChairs() {
  // print stays on the same line. println finishes the line.
  Serial.print("L1 raw: ");
  Serial.print(chair1Reading);
  Serial.print(" occupied: ");
  Serial.println(chair1Occupied);
  Serial.print("L2 raw: ");
  Serial.print(chair2Reading);
  Serial.print(" occupied: ");
  Serial.println(chair2Occupied); // 1 = true / occupied; 0 = false / free.
}

String makeSeatMessage() {
  // JSON is a text format with named fields. A JSON boolean has NO quotes.
  // In C++ source, \" means put a quotation mark INSIDE a string.
  String message = "{\"v\":1,\"seats\":[";
  message += "{\"id\":\"L1\",\"occupied\":";
  if (chair1Occupied) {
    message += "true";
  } else {
    message += "false";
  }
  message += ",\"raw\":";
  message += String(chair1Reading); // Convert a number to text.
  message += "},";
  message += "{\"id\":\"L2\",\"occupied\":";
  if (chair2Occupied) {
    message += "true";
  } else {
    message += "false";
  }
  message += ",\"raw\":";
  message += String(chair2Reading);
  message += "}]}";
  return message;
}

unsigned long lastSampleTime = 0;
unsigned long lastSendTime = 0;

void setup() {
  Serial.begin(115200);
  prepareWifi();
  analogReadResolution(10);
}

void loop() {
  // Use elapsed time instead of a long delay: two jobs need different intervals.
  if (millis() - lastSampleTime >= 50) {
    lastSampleTime = millis();
    readChairs();
  }
  if (millis() - lastSendTime >= 2000) {
    lastSendTime = millis();
    printChairs();
    String message = makeSeatMessage();
    Serial.println(message); // Inspect exactly what we are sending.
    sendToPi("/api/seats", message);
  }
}

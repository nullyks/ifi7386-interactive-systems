// Wi-Fi fault isolation only. No sensors, Pi server or internet required.
// Select Arduino UNO R4 WiFi. Open Serial Monitor at 115200, then press Reset.
#include <WiFiS3.h>

// For Group 2, change the name to IFI7386-G2.
// It must match the ACTIVE hotspot, including upper/lowercase letters.
// Both Pi hotspots use OPEN Wi-Fi: there is no password setting.
const char WIFI_NAME[] = "IFI7386-G1";

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

const char* encryptionName(int type) {
  switch (type) {
    case ENC_TYPE_WEP: return "WEP";
    case ENC_TYPE_WPA: return "WPA";
    case ENC_TYPE_WPA2: return "WPA2";
    case ENC_TYPE_WPA2_ENTERPRISE: return "WPA2 enterprise";
    case ENC_TYPE_WPA3: return "WPA3";
    case ENC_TYPE_NONE: return "OPEN";
    case ENC_TYPE_AUTO: return "Auto";
    default: return "Unknown";
  }
}

void printLinkStatus() {
  int status = WiFi.status();
  Serial.print("Current status: ");
  Serial.print(wifiStatusName(status));
  Serial.print(" (");
  Serial.print(status);
  Serial.println(")");
  if (status == WL_CONNECTED) {
    IPAddress address = WiFi.localIP();
    Serial.print("Arduino IP: ");
    Serial.println(address);
    if (address == IPAddress(0, 0, 0, 0)) {
      Serial.println("WIFI_NO_IP: no usable IPv4 address yet.");
    } else {
      Serial.println("WIFI_IP_OK: next test the Pi server, not Wi-Fi association.");
    }
    Serial.print("Signal (dBm): ");
    Serial.println(WiFi.RSSI());
  }
}

void scanForHotspot() {
  Serial.println("Scanning nearby Wi-Fi networks...");
  int count = WiFi.scanNetworks();
  if (count < 0) {
    Serial.println("SCAN_FAILED: check the Wi-Fi module and firmware.");
    return;
  }
  bool found = false;
  for (int index = 0; index < count; index++) {
    String name = WiFi.SSID(index);
    Serial.print(name);
    Serial.print(" | channel ");
    Serial.print(WiFi.channel(index));
    Serial.print(" | ");
    Serial.print(WiFi.RSSI(index));
    Serial.print(" dBm | ");
    Serial.println(encryptionName(WiFi.encryptionType(index)));
    if (name == WIFI_NAME) {
      found = true;
      if (WiFi.encryptionType(index) != ENC_TYPE_NONE) {
        Serial.println("TARGET_NOT_OPEN: change the Pi hotspot security to OPEN.");
      }
    }
  }
  if (found) {
    Serial.println("TARGET_SEEN: the Arduino can see the expected SSID.");
  } else {
    Serial.println("TARGET_NOT_SEEN: check the SSID, 2.4 GHz band and channel.");
  }
}

void setup() {
  Serial.begin(115200);
  // A bounded wait gives Serial Monitor time to open; it cannot wait forever.
  unsigned long serialStarted = millis();
  while (!Serial && millis() - serialStarted < 3000) {
    delay(10);
  }
  Serial.println("UNO R4 WiFi connection check");
  Serial.print("Target SSID: ");
  Serial.println(WIFI_NAME);
  Serial.println("Wi-Fi security: OPEN (no password)");
  Serial.print("Wi-Fi firmware: ");
  Serial.println(WiFi.firmwareVersion());
  byte mac[6] = {0}; // Leave a defined value even if the module does not reply.
  WiFi.macAddress(mac);
  Serial.print("Arduino MAC: ");
  for (int index = 0; index < 6; index++) {
    if (index > 0) {
      Serial.print(":");
    }
    if (mac[index] < 16) {
      Serial.print("0");
    }
    Serial.print(mac[index], HEX);
  }
  Serial.println();
  Serial.print("Board package's firmware reference: ");
  Serial.println(WIFI_FIRMWARE_LATEST_VERSION);

  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("WIFI_NO_MODULE: check the connectivity firmware before retrying.");
    return;
  }

  scanForHotspot();
  WiFi.setTimeout(20000); // Allow twenty seconds for this single diagnostic attempt.
  Serial.println("Trying one connection; this can take twenty seconds...");
  unsigned long attemptStarted = millis();
  // Only the SSID is passed: this is the OPEN-network overload.
  int result = WiFi.begin(WIFI_NAME);
  Serial.print("WiFi.begin result: ");
  Serial.print(wifiStatusName(result));
  Serial.print(" (");
  Serial.print(result);
  Serial.println(")");
  Serial.print("Attempt duration (ms): ");
  Serial.println(millis() - attemptStarted);
  printLinkStatus();
  Serial.println("Status repeats below; press Reset for a new scan and connection attempt.");
}

void loop() {
  delay(5000);
  // Also shows a connection that finishes after begin() has returned.
  printLinkStatus();
}

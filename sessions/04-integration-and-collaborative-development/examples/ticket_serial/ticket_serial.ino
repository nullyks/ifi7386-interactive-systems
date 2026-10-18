// STEP 1: read and record real tag UIDs. No Wi-Fi or Pi needed.

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

void setup() {
  Serial.begin(115200);
  startReader();
}

void loop() {
  readNewCard(); // The function prints each new UID to Serial Monitor.
}

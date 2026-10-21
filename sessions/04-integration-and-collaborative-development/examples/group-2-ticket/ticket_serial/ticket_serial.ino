// STEP 1: read and record real tag UIDs. No Wi-Fi or Pi needed.

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

void setup() {
  Serial.begin(115200);
  startReader();
}

void loop() {
  readNewCard(); // The function prints each new UID to Serial Monitor.
  delay(20); // A short pause between attempts; no long wait after a scan.
}

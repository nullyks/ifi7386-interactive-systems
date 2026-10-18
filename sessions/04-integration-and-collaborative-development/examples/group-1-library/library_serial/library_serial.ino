// STEP 1: two FSRs and Serial Monitor. No Wi-Fi or Pi needed.

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

// setup runs ONCE when the board starts or is reset.
void setup() {
  Serial.begin(115200); // Match this speed in Serial Monitor.
  analogReadResolution(10); // 10 bits gives values 0 through 1023.
}

// loop runs AGAIN AND AGAIN until power is removed.
void loop() {
  readChairs();
  printChairs();
  delay(100); // Wait 100 milliseconds so the output remains manageable.
}

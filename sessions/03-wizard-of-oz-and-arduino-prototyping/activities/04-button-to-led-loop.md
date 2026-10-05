# Activity 04 - Button to LED Loop

[← Session 3](../README.md) · [← Previous activity](03-first-upload-and-output.md)

**Time:** 30 minutes · **Format:** individual or shared circuit and sketch

## Goal

Build a complete physical interaction: a press is sensed, a rule is applied, and the user sees feedback.

## Materials

UNO, USB data cable, breadboard, pushbutton, LED, **470 Ω resistor**, and jumper wires.

## Steps

1. Disconnect USB power. Connect the button between pin 3 and GND. Configure pin 3 as `INPUT_PULLUP`.
2. Connect digital pin 8 → 470 Ω resistor → LED anode (long leg); connect the LED cathode (short leg) → GND. Check the pin diagram before reconnecting power.
3. Read the button with `digitalRead()`. Remember that an unpressed button gives `HIGH` and a pressed button gives `LOW` in this arrangement.
4. Make the LED turn on while the button is pressed and off when released. Upload and test.
5. Add `Serial.begin(9600)` and print the read value or a short status. Open Serial Monitor at the same baud rate.
6. Test a quick press, a long press, and release. Explain what the board reads and what the person sees.
7. If time permits, change the rule so one press changes a stored `active` state. Detect a new press rather than counting every pass through `loop()` while held.

## Working starting sketch

```cpp
const int buttonPin = 3;
const int ledPin = 8;
int previousReading = HIGH;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int reading = digitalRead(buttonPin);
  digitalWrite(ledPin, reading == LOW ? HIGH : LOW);

  if (reading != previousReading) {
    Serial.println(reading == LOW ? "Pressed" : "Released");
    previousReading = reading;
  }
}
```

This sketch reports a change in the raw button reading. A mechanical button can briefly bounce between states, so repeated messages around one press are possible; a project that counts presses will need a more robust state-change or debounce rule.

## Safety and troubleshooting

Change wiring only with power disconnected. Never connect 5 V directly to GND. Do not omit the LED resistor. If the LED stays off, check polarity, output pin, resistor placement, and whether the code treats `LOW` as pressed. A basic delay-based button example may count a long hold more than once; note that limitation before using it for a project feature.

## Output

A circuit photo or sketch, working code, and a short observation: input value → rule → visible output. Mark any unresolved wiring or timing issue.

## Source route

- [Button input](https://github.com/nullyks/Arduino-sissejuhatus/blob/main/materjalid/4_Nupu_lugemine.md)
- [LED output](https://github.com/nullyks/Arduino-sissejuhatus/blob/main/materjalid/5_LED_juhtimine.md)

[Next activity →](05-component-stations.md)

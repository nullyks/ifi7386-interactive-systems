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
4. Enter the sketch below. It makes the LED follow the button and prints a message when the button changes state.
5. Upload and test a quick press, a long press, and release. Explain what the board reads and what the person sees.
6. Open Serial Monitor and set its speed to **9600 baud**. Press and release the button and read the messages.
7. If time permits, change the rule so one press changes a stored `active` state. Ask the instructor to help add one change at a time.

## Working starting sketch

```cpp
// These constants give names to the pins used in the circuit.
const int buttonPin = 3;
const int ledPin = 8;

// This variable remembers the button reading from the previous check.
int previousButtonState = HIGH;

void setup() {
  // The button connects pin 3 to GND when pressed.
  pinMode(buttonPin, INPUT_PULLUP);

  // The LED pin sends a signal out to the LED.
  pinMode(ledPin, OUTPUT);

  // Start communication with the computer for Serial Monitor.
  Serial.begin(9600);
}

void loop() {
  // Read the current button state.
  int buttonState = digitalRead(buttonPin);

  // INPUT_PULLUP means LOW when pressed and HIGH when released.
  if (buttonState == LOW) {
    // The button is pressed, so turn the LED on.
    digitalWrite(ledPin, HIGH);
  } else {
    // The button is released, so turn the LED off.
    digitalWrite(ledPin, LOW);
  }

  // Check whether the button state changed since the last check.
  if (buttonState != previousButtonState) {
    if (buttonState == LOW) {
      Serial.println("Button is pressed");
    } else {
      Serial.println("Button is released");
    }

    // Remember this state for the next time loop() runs.
    previousButtonState = buttonState;
  }
}
```

Each line in `loop()` runs repeatedly. `if` checks whether a condition is true; `else` describes what to do when it is false. The variable `previousButtonState` lets the sketch print a message only when it notices a change. A mechanical button can briefly bounce between states, so repeated messages around one press are possible; a project that counts presses will need a more robust debounce rule.

In a condition, `==` asks whether two values are equal. A single `=` stores a value in a variable. The two signs have different jobs.

## Safety and troubleshooting

Change wiring only with power disconnected. Never connect 5 V directly to GND. Do not omit the LED resistor. If the LED stays off, check polarity, output pin, resistor placement, and whether the code treats `LOW` as pressed. Mechanical button bounce may produce more than one message for a single press; test this before using button presses as a precise count.

## Output

A circuit photo or sketch, working code, and a short observation: input value → rule → visible output. Mark any unresolved wiring or timing issue.

## Source route

- [Button input](https://github.com/nullyks/Arduino-sissejuhatus/blob/main/materjalid/4_Nupu_lugemine.md)
- [LED output](https://github.com/nullyks/Arduino-sissejuhatus/blob/main/materjalid/5_LED_juhtimine.md)

[Next activity →](05-component-stations.md)

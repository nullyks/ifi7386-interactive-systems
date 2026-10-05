# Activity 03 - First Upload and Output

[← Session 3](../README.md) · [← Previous activity](02-map-the-interaction-to-arduino.md)

**Time:** 25 minutes · **Format:** individual kits or shared build in pairs and teams

## Goal

Verify that a sketch reaches the correct board, then make and observe one change in output.

## Steps

1. Identify whether your board is UNO R3 or UNO R4 WiFi and select the correct USB data cable.
2. Connect the board, open Arduino IDE, and select the matching board and port.
3. Open a new sketch and enter the example below. Read the comments to see what each line does.
4. Upload. Confirm that the on-board LED blinks. If it does not, check the board, port, cable, and upload message.
5. Change `waitTime` from `1000` to `250`, upload again, and describe the difference you observe.
6. Point to the lines that turn the LED on and off. Explain why `loop()` causes the sequence to repeat.

## First sketch

```cpp
// LED_BUILTIN is the pin number for this board's built-in LED.
// This constant gives us the correct pin number for this board.
const int ledPin = LED_BUILTIN;

// This number is the time to wait in milliseconds.
// 1000 milliseconds is one second.
int waitTime = 1000;

void setup() {
  // Tell the board that it will send a signal out through this pin.
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Send a HIGH signal to turn the LED on.
  digitalWrite(ledPin, HIGH);

  // Wait for the number of milliseconds stored in waitTime.
  delay(waitTime);

  // Send a LOW signal to turn the LED off.
  digitalWrite(ledPin, LOW);

  // Wait again before loop() starts over.
  delay(waitTime);
}
```

`setup()` runs once after the board starts. `loop()` runs over and over. `HIGH` and `LOW` are the two digital signal states. `OUTPUT` tells the board that this pin sends a signal to a component. `const int` creates a named number that the program does not change; `int waitTime` creates a number that you can change in the sketch.

## Checkpoint

Show an instructor or another student the changed blink rate and explain the board, port, sketch, and output. If sharing a board, change roles so each student can explain the result.

## Output

A successful upload, one intentional code change, and a short note on the observed output.

## Source route

- [IDE setup](https://github.com/nullyks/Arduino-sissejuhatus/blob/main/materjalid/1_Tarkvara_paigaldamine_ja_seadistamine.md)
- [Connection and upload](https://github.com/nullyks/Arduino-sissejuhatus/blob/main/materjalid/2_%C3%9Chendamine_ja_%C3%BCleslaadimine.md)
- [UNO pins](https://github.com/nullyks/Arduino-sissejuhatus/blob/main/materjalid/3_Arduino_UNO_viigud.md)

[Next activity →](04-button-to-led-loop.md)

# Activity 03 - First Upload and Output

[← Session 3](../README.md) · [← Previous activity](02-map-the-interaction-to-arduino.md)

**Time:** 25 minutes · **Format:** individual kits or shared build in pairs and teams

## Goal

Verify that a sketch reaches the correct board, then make and observe one change in output.

## Steps

1. Identify whether your board is UNO R3 or UNO R4 WiFi and select the correct USB data cable.
2. Connect the board, open Arduino IDE, and select the matching board and port.
3. Open the built-in **Blink** example. Find `setup()`, `loop()`, `pinMode()`, `digitalWrite()`, and `delay()`.
4. Upload. Confirm that the on-board LED blinks. If it does not, check the board, port, cable, and upload message.
5. Change one delay value, upload again, and describe the difference you observe.
6. Point to the sketch line that sets the output state and explain why `loop()` causes repeated behaviour.

## Checkpoint

Show an instructor or another student the changed blink rate and explain the board, port, sketch, and output. If sharing a board, change roles so each student can explain the result.

## Output

A successful upload, one intentional code change, and a short note on the observed output.

## Source route

- [IDE setup](https://github.com/nullyks/Arduino-sissejuhatus/blob/main/materjalid/1_Tarkvara_paigaldamine_ja_seadistamine.md)
- [Connection and upload](https://github.com/nullyks/Arduino-sissejuhatus/blob/main/materjalid/2_%C3%9Chendamine_ja_%C3%BCleslaadimine.md)
- [UNO pins](https://github.com/nullyks/Arduino-sissejuhatus/blob/main/materjalid/3_Arduino_UNO_viigud.md)

[Next activity →](04-button-to-led-loop.md)

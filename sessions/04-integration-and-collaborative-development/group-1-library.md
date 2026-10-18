# Group 1 — Two library chairs

[Session 4](README.md) · [Setup](setup.md) · [Stage 1: serial-only sketch](examples/group-1-library/library_serial/library_serial.ino) · [Stage 2: network sketch](examples/group-1-library/library/library.ino)

## Parts and wiring

One UNO R4 WiFi, two FSRs, two 10 kΩ resistors, breadboard, wires, USB data cable and prepared Pi/browser. Disconnect USB before changing wiring. Each sensor needs its own voltage divider:

```text
UNO 5 V ── FSR 1 ──┬── A0
                    └── 10 kΩ ── GND
UNO 5 V ── FSR 2 ──┬── A1
                    └── 10 kΩ ── GND
```

All grounds common. Pressure lowers FSR resistance so the reading rises. Begin on the bench; then mount without sharp bending, overload or trip/pull hazards. Use a suitable pad to distribute pressure into the sensor's active area. A bag may also trigger occupancy: pressure is not proof of a seated person.

## Stage 1 — Arduino and FSRs ONLY (minutes 10–45)

1. Open `examples/group-1-library/library_serial/library_serial.ino`. This sketch has NO Wi-Fi code. Select Arduino UNO R4 WiFi and your USB port, then upload.
2. Open Serial Monitor at **115200**. Read `L1 raw`, `L2 raw` and occupied (1=true, 0=false). Press each sensor separately, then release. Ten-bit raw readings range from 0 to 1023.
3. Mount and record at least five empty readings and five occupied readings per chair. Finger pressure alone is not final calibration.
4. Set `CHAIR_1_OFF` above stable empty readings and `CHAIR_1_ON` below stable occupied readings; repeat for `CHAIR_2_OFF` and `CHAIR_2_ON`. OFF must be lower than ON. Example ONLY: empty 50–150, occupied 650–850 → OFF=400, ON=550. Upload again.
5. If ranges overlap, improve mounting/divider resistance/sensor suitability first. Thresholds cannot separate overlapping evidence.
6. Repeat empty → occupied → empty three times on each chair and then both together. **C1:** save the four thresholds and show correct independent states in Serial Monitor before using Pi.

## Stage 2 — Send the data, THEN display it (minutes 45–90)

1. Use your actual readings to explain one [JSON message](data-contract.md).
2. Follow [Pi setup](setup.md): join prepared hotspot and start host. No simulator is required on the main route.
3. Open `examples/group-1-library/library/library.ino`. Copy your FOUR calibrated thresholds from the serial-only sketch; opening another sketch does not transfer values automatically. Check Wi-Fi name/password and Pi address at the top.
4. Upload; Serial Monitor now shows local readings, outgoing JSON and response. **C2:** obtain HTTP 200. If it fails, first check hotspot/server/address. Local sensing should already be verified.
5. Open http://10.42.0.1:3000. Verify L1, L2 and both chairs; page shows raw readings, labels and colours. **C3:** physical input changes the correct seat. Expect a few seconds latency.

The sketch smooths readings and uses hysteresis: above ON becomes occupied; below OFF becomes free; between them keep previous state. Initial local state is free until threshold crossing: let readings settle. Stage 1 reads approximately every 100 ms; Stage 2 aims for 50 ms but is delayed by network calls; adequate for this slow demonstration, not fast control. Complete snapshots every two seconds repair a missed update on a later report.

After core functionality, choose one change: tune separate thresholds, adapt map geometry in `index.html`, or improve labels. IDs L1/L2 must agree across all layers. More seats require host validation and map changes too.

[Run tests](testing.md), including unplugging UNO for >10 seconds: seats must become unknown and recover after reconnecting. An unplugged FSR alone can read zero and appear free; heartbeat does not detect a broken sensor wire. Record this limitation.

## Explore the table areas

The page now includes Table 1 (2 sensor seats), Table 2 (4 seats) and Table 3 (6 seats). Click anywhere inside a table area to open its description; close it with the button or Escape. Tab plus Enter/Space also opens an area. Added white dashed chairs have no sensors and must not be described as free. Descriptions are example library uses; change them in `tableDescriptions` in the HTML file. Arduino pins, thresholds, messages and server validation remain unchanged.

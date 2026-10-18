# Instructor lesson plan — Session 4

135 minutes · Student materials in English · Integration and Collaborative Development

## Purpose and preparation

Build on the previous Arduino introduction and selected project slices. Prioritise a complete observable input-to-output chain, a shared contract and recovery evidence over interface polish.

Complete preparation OUTSIDE the 135 minutes:

- Prepare one Pi per group, or explicitly use a shared Pi. Verify the 2.4 GHz hotspot, fixed 10.42.0.1 address, Node >=18, copied examples and browser access from another device. Keep local keyboard/monitor or Ethernet access.
- Install UNO R4 board support and Adafruit PN532 with BusIO on programming laptops. Check data cables and Wi-Fi firmware. Keep offline copies; do not allocate class time to OS or library installation.
- G1: two FSRs, two 10 kΩ resistors, breadboard, wires and safe chair mounting. Pretest actual loading, not just finger pressure.
- G2: inspect actual PN532 module, SPI selector and documented supply/logic voltages. Prepare a verified compatible SPI translator/adapter and 2–3 ISO14443A tags. Resolve module-specific wiring BEFORE class; the ASIN alone does not establish voltage tolerance.
- Run both examples on the actual kits. Local compilation and API tests do not prove RF, hotspot or sensing performance. Keep a known working host/circuit, measured FSR values and real UIDs as fallback.

## Facilitation

**0–45: Arduino and actual sensors only.** Recall input/rule/output briefly, then wire with power off. Open `library_serial/library_serial.ino` or `ticket_serial/ticket_serial.ino`. Everyone helps wire, upload, observe or record. G1 calibrates each mounted chair and repeats transitions; G2 records 2–3 actual UIDs and verifies rescanning. At C1 (minute 45) require reliable local Serial Monitor evidence. Do not introduce HTTP or run a host simulator first. If blocked after five minutes, provide a known working circuit/reader. A simulator cannot satisfy C1.

**45–90: transmission, then display.** From 45–55 build one JSON example from the values just measured. Assign hardware/firmware, host/UI and integration/test responsibilities now. From 55–70 join the prepared Pi hotspot, start the supplied server and upload the network sketch. G1 must copy its measured thresholds into this second sketch. At C2 require HTTP 200 from actual input. Then open the browser, copy real UIDs into mapping, restart host and verify seat/route. At C3 (minute 90), physical input must change the correct screen element. Use simulation only to isolate a host fault AFTER local sensing; label it explicitly.

**90–135: understand, modify, test, demonstrate.** Use 90–105 for reading comments and ONE change; do not require beginners to write the networking helper from scratch. From 105–125 run acceptance/recovery tests. Preserve these if behind schedule; drop the extension first. Give each group about four minutes plus one minute feedback for demonstration and handover. Breaks inside the slot come from optional modification time. Incomplete integration stays marked incomplete.

## Formative assessment

Record demonstrated / partial / not yet for: physical-to-web integration; coherent responsibilities and field names; calibrated sensing or real ticket mappings; feedback beyond colour; failure/recovery; reproducible team handover. This is formative evidence, not a new numeric grading scheme.

Ask: where is occupancy decided? Can a bag trigger it? Why does an idle reader need heartbeats? Does ready=true prove the antenna works? Can a scan be lost or duplicated? Can a peer follow the route from the entrance? Which layers change when adding a seat?

# Session 4 — Integration and Collaborative Development

[Course home](../../README.md) · [Sessions](../README.md)

**135 minutes in three 45-minute blocks · Working language: English**

Build your selected Hi-Fi slice as one integrated system. Each group uses its own independent server, page and Arduino examples. Get your group’s supplied example working first, then change one meaningful feature. The display is a browser on the Pi monitor or a computer connected to its Wi-Fi; no Arduino screen module is required.

- Group 1: two FSRs → one UNO R4 WiFi → Pi 400 → library plan with two seats.
- Group 2: RFID-RC522 V1.33 with AMRFID → UNO R4 WiFi → Pi 400 → hall plan with seat and route for 2–3 tickets.

By the end you can trace physical input through firmware, HTTP and JSON to visible feedback; agree a data contract; distinguish valid, waiting, unknown and error states; integrate contributions across layers; and demonstrate recovery.

## Practical route

| Activity | Checkpoint / result |
|---|---|
| Recall the selected interaction; identify parts and upload procedure | Explain input → Arduino rule → Serial Monitor |
| Wire sensors with power disconnected; upload the serial-only sketch | Actual FSR readings OR real RFID UIDs in Serial Monitor |
| Calibrate both chairs OR collect 2–3 UIDs; repeat the local interaction | C1: reliable local data, saved thresholds/UIDs; no network needed |
| Turn those measured values into one JSON message; assign layer/file owners | Explain the data contract using YOUR measurements |
| Join prepared Pi hotspot; start host; upload networked sketch | C2: real Arduino data reaches Pi, HTTP 200 |
| Open browser; inspect map; register real UID mappings; reload/restart as needed | C3: physical input changes correct seat / route on screen |
| Read the commented code; make ONE useful change | Explain the changed variable/function and result |
| Acceptance and recovery tests | Pass/fail evidence and one issue addressed |
| Two demonstrations, peer feedback and handover | Save working slice, limitations and next step |

If breaks must fit inside the slot, take them from optional modification time. Drop extension work first if behind schedule. A team using simulation must label integration unfinished.

## Open in order

1. [How to read the beginner examples](code-guide.md).
2. **Arduino first:** [Group 1: library chairs](group-1-library.md) OR [Group 2: ticket guidance](group-2-ticket.md). Complete Stage 1 without Pi/Wi-Fi.
3. **Only after C1:** [Data contract](data-contract.md), then [Pi setup and transmission](setup.md).
4. **After HTTP 200:** open the browser and finish Stage 2 in your group guide.
5. [Acceptance tests and handover](testing.md).

[Group 1 application](examples/group-1-library/README.md) · [Group 2 application](examples/group-2-ticket/README.md) · [Verification and sources](verification.md)

If Arduino cannot join the Pi hotspot, including when a phone connects, use [Wi-Fi connection diagnosis](wifi-troubleshooting.md) before proceeding to the server. It includes a separate sensor-free sketch and the evidence needed to identify the failing step.

## Explain the complete loop

```text
FSRs / RFID → Arduino → HTTP POST + JSON over Pi Wi-Fi
                                  ↓
                         Node.js holds latest state
                                  ↓
                    Browser GET /api/state every second
                                  ↓
                          Map, text and feedback
```

Arduino is a client; Pi is access point and web server. The browser polls the Pi, not Arduino. Seats use repeated snapshots; tickets use events and reader heartbeats. Expect a few seconds of latency. State resets when the server restarts. Routes start at one fixed entrance; this is not live indoor positioning.

## Collaborative development

During Stage 1, everyone participates in wiring, reading or recording actual sensor data; nobody starts on the host yet. After C1, the hardware/firmware owner preserves the working sensor code, the host/UI owner starts the prepared Pi server, and the integration/test owner maintains IDs and records checkpoints. Simulation is an optional fault-isolation tool after local sensing, not the first activity. In larger teams pair within roles; rotate who explains each layer. Agree field names before combining changes. Give different members ownership of firmware, server/mapping, and interface files. Keep a known working copy and integrate one change at a time. Log time, change, expected result, actual result and next action.

Minimum G1 result: both chairs work independently, thresholds come from measurements, missing data becomes unknown. Minimum G2 result: two real tags select distinct seats, unknown tickets give feedback, old guidance disappears. Both teams explain a request and show recovery.

After the core works, choose ONE: clearer map/labels, better FSR thresholds, a third ticket or improved route wording. Keep databases, booking, accounts and automatic routing for later. Before next meeting save code, wiring photo, measured thresholds or UID mapping, test log, short demo and one usability question for participant testing.

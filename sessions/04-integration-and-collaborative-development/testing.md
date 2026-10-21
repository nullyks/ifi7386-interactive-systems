# Acceptance tests and handover

[Session 4](README.md)

First record C1 from the serial-only sketch: G1 shows two independently responding sensors with measured thresholds; G2 shows repeated real UIDs for 2–3 tags. Next record C2 (actual POST accepted with HTTP 200), then C3 (correct browser feedback). Only then run the complete-system tests below.

Stop any optional simulators first. Record PASS/FAIL, actual result, photo/log evidence and next action. Simulation can isolate a fault but must be labelled simulated. After a fix rerun the failed test and main path.

| Group | Action | Expected |
|---|---|---|
| Both | Start your own group’s host without devices | G1: seats unknown. G2: reader offline, no route |
| G1 | Empty both mounted chairs | Both free after settling |
| G1 | Occupy L1, L2, both | Correct independent states in a few seconds |
| G1 | Release each; repeat three cycles | Correct return, no rapid chatter |
| G1 | Click each of the three table areas | Correct separate description opens; close button/Escape works |
| G1 | Tab to table area, activate with Enter/Space | Same description is accessible by keyboard |
| G1 | Inspect added chairs while sensor values change | White dashed chairs remain unmeasured; only L1/L2 change sensor state |
| G1 | Unplug UNO; wait >10 s | Seats grey/unknown |
| G1 | Reconnect | Fresh states return automatically |
| G2 | Scan 2–3 registered tags | Distinct correct seats, paths and text |
| G2 | Scan unregistered compatible tag | Unknown ticket; old route removed |
| G2 | Hold tag, remove >2 s, rescan | No event flood; rescan works |
| G2 | Scan then wait >15 s | Prompt returns; heartbeat keeps reader online |
| G2 | Unplug UNO; wait >10 s | Reader offline; route hidden |
| G2 | Reconnect and scan again | Correct guidance recovers |
| G2 | Observe status before scanning a known card | Initialised means the code ran; only a real UID confirms reading works |
| Both | Stop host while page open | Host unavailable; stale success hidden |
| Both | Restart host, wait for messages | Browser recovers without reload |
| Both | Send malformed JSON / invalid ID | HTTP 400; valid state not overwritten |

Run `npm test` in `examples/group-1-library/host` OR `examples/group-2-ticket/host` for your own API checks; these do not replace hardware/browser tests.

Group 2 uses RC522 with AMRFID. Its heartbeats prove the Arduino is online, not that the reader is electrically connected or can read a card. The optional `node simulate.js reader-error` check sends `ready: false` and must clear the previous route; record this as simulated. Do not claim the firmware detects a disconnected RC522. Correct wiring with USB disconnected, reconnect, reset and scan a known card to verify recovery.

Demonstration: about four minutes per group and one minute feedback. Show main interaction, one failure/recovery, one JSON message, and main limitation. Each member explains a layer.

Save: team/date/version; actual wiring photo; Pi SSID/IP/startup path (avoid publishing private credentials); measured FSR thresholds or real UID mapping; test results; implemented versus simulated parts; modification/reason; known limitation; next usability question; next owner/action. Keep firmware and full host folder together so another member can restart the system.

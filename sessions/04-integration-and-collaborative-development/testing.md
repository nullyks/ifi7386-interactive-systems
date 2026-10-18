# Acceptance tests and handover

[Session 4](README.md)

First record C1 from the serial-only sketch: G1 shows two independently responding sensors with measured thresholds; G2 shows repeated real UIDs for 2–3 tags. Next record C2 (actual POST accepted with HTTP 200), then C3 (correct browser feedback). Only then run the complete-system tests below.

Stop any optional simulators first. Record PASS/FAIL, actual result, photo/log evidence and next action. Simulation can isolate a fault but must be labelled simulated. After a fix rerun the failed test and main path.

| Group | Action | Expected |
|---|---|---|
| Both | Start host without devices | Seats unknown; reader offline; no route |
| G1 | Empty both mounted chairs | Both free after settling |
| G1 | Occupy L1, L2, both | Correct independent states in a few seconds |
| G1 | Release each; repeat three cycles | Correct return, no rapid chatter |
| G1 | Unplug UNO; wait >10 s | Seats grey/unknown |
| G1 | Reconnect | Fresh states return automatically |
| G2 | Scan 2–3 registered tags | Distinct correct seats, paths and text |
| G2 | Scan unregistered compatible tag | Unknown ticket; old route removed |
| G2 | Hold tag, remove >2 s, rescan | No event flood; rescan works |
| G2 | Scan then wait >15 s | Prompt returns; heartbeat keeps reader online |
| G2 | Unplug UNO; wait >10 s | Reader offline; route hidden |
| G2 | Reconnect and scan again | Correct guidance recovers |
| Both | Stop host while page open | Host unavailable; stale success hidden |
| Both | Restart host, wait for messages | Browser recovers without reload |
| Both | Send malformed JSON / invalid ID | HTTP 400; valid state not overwritten |

Run `npm test` in examples/host for API checks; these do not replace hardware/browser tests.

Demonstration: about four minutes per group and one minute feedback. Show main interaction, one failure/recovery, one JSON message, and main limitation. Each member explains a layer.

Save: team/date/version; actual wiring photo; Pi SSID/IP/startup path (avoid publishing private credentials); measured FSR thresholds or real UID mapping; test results; implemented versus simulated parts; modification/reason; known limitation; next usability question; next owner/action. Keep firmware and full host folder together so another member can restart the system.

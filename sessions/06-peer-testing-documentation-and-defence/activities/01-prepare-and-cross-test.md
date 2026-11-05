# Activity 01 — Prepare and Cross-Test

[Session 6](../README.md) · [Project record template](../templates/project-record.md) · [Next: design discussion](02-discuss-design-decisions.md)

**Time: 40 minutes · 10 minutes of preparation, then two 15-minute rounds**

## 1. Prepare a testable version

Pair with another team. In round 1, Team A hosts and Team B tests. In round 2, swap. With more teams, work in pairs at the same time; agree any remaining team's rotation with the instructor.

1. Run the prototype on its own Pi and hotspot. Visitors use that Pi's browser and your physical input; they do not need a clone or GitHub write access.
2. Record the date, server code commit on the Pi (`git rev-parse --short HEAD`), firmware source last uploaded and a hardware revision such as `HW-01`. If the firmware version is not known, write **UNVERIFIED**. Record any uncommitted code/calibration changes; a commit alone would not identify that build.
3. Agree one question about the updated interaction: for example, **Can a new participant distinguish unavailable data from an available seat?**
4. Prepare one main task and one failure/recovery task. Write the expected result privately in the test record. Keep the code and wiring fixed during both rounds.
5. Assign a facilitator, an observer and a hardware operator in the hosting team. The visiting team chooses a participant; other visitors observe without coaching. Explain note-taking and obtain consent. Use anonymous labels such as P1.

## 2. Give a goal, then watch

Use these tasks as starting points; adapt them to what your current prototype actually implements.

| Prototype | Participant's main task | Failure/recovery situation |
|---|---|---|
| Library chairs | “You need a place to work. Use this display to decide where you could sit, and explain what you can and cannot tell.” The operator changes the two sensor chairs independently. | After a working reading, the operator disconnects Arduino's USB power without touching wires. Ask what the display now tells the participant. Reconnect and check recovery. |
| Ticket guidance | “You have this ticket and need to find your seat. Use the prototype to work out where to go.” Use a known test tag, then a compatible tag absent from the current mapping if available. | After a successful scan, disconnect Arduino's USB power. Ask whether the old guidance can still be trusted. Reconnect, then scan again to check recovery. |

For the supplied code, seat reports and reader heartbeats become stale after **more than 10 seconds**; ticket guidance also expires after **15 seconds**. Allow for browser refresh. If your team changed these rules, record and test the current values. Do not claim that the reader detects a broken antenna or that a disconnected FSR wire is detected automatically. See the [data contract](../../04-integration-and-collaborative-development/data-contract.md).

During each 15-minute round:

- **2 minutes:** explain the situation and participation; do not demonstrate the controls.
- **8 minutes:** run the main and failure/recovery tasks. Ask the participant to say what they expect and understand. Record hesitation, actions, feedback and any help given. If feasible, also check whether status is understandable without colour, or whether a relevant control works with the keyboard.
- **3 minutes:** ask “What did you think was happening?”, “What was unclear?” and “What would you try next?”
- **2 minutes:** confirm the observation notes and swap roles/stations.

Avoid leading questions such as “Was the new label clearer?” If the participant is stuck, record the difficulty before giving help; mark the outcome **assisted**. The hardware operator handles disconnection and reconnection. Stop if the setup becomes unsafe.

## 3. Save the observation before interpreting it

Use the peer-test section of the [project record template](../templates/project-record.md). Each team keeps a record of **its own solution being tested**, with at least three observations, the task outcomes and evidence links where available.

| Observation | Interpretation | Possible action |
|---|---|---|
| Example only: P1 called a grey chair “free” after the board had been disconnected. | “Unknown” may not be explained clearly enough. | Consider explicit unavailable-data text, then test whether it is understood. |

This example is not your team's result. Preserve actual failures and help given. If hardware cannot run, record a **blocked** task or a clearly labelled simulation; the physical test remains unverified. A peer participant also may not represent your intended user or context.

**Output:** a versioned peer-test record with one main task, one failure/recovery task, outcomes, at least three observations and one limitation of the test.

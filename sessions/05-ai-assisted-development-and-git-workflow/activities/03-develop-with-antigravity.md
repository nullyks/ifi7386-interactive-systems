# Activity 03 — Develop with Antigravity

[Session 5](../README.md) · [Change cards](02-find-and-specify-improvements.md) · [Publish and test next](04-publish-update-and-test.md)

**Time: about 20 minutes per round · Use the graphical desktop app on the development computer**

## 1. Open the existing project

Launch Google Antigravity and sign in. Create a project with **New Project → Add Folder**, select your development clone's `team-project` root and choose **Create**. Start a conversation in **Local mode**, so the agent edits this same clone. In an older desktop version, use its equivalent open-folder action. Confirm the displayed path; do not open the course folder or a second accidental copy. [Official setup](https://antigravity.google/docs/getting-started) and [local project mode](https://antigravity.google/docs/projects/).

## 2. Ask the agent to understand before changing

Use this starting prompt and replace the group description:

```text
This is our existing IFI7386 group project: [library seats / ticket guidance].
Read README.md, host/server.js, host/index.html, host/test.js and our network
Arduino sketch. For ticket guidance, also read host/tickets.json.

Explain which code runs on the development computer, Pi and Arduino, and trace
one input to visible feedback. Suggest three small improvements to the server
or interface and explain what each would help us test. Do not edit files yet.
```

Compare the answer with your observation and the actual files. Ask about any line you cannot explain. Choose your own change card; keep the other suggestions for later.

## 3. Give a bounded implementation prompt

```text
Observed problem: [what we saw].
Desired behaviour: [what the user should experience].
Scope: [the relevant files/layer].

Acceptance checks:
1. Given [state/action], expect [specific visible or API result].
2. Given [missing data or failure], expect [specific result].
Regression check: [the original physical interaction that must still work].

Keep the existing Node server and plain HTML/SVG/JavaScript structure.
Preserve Arduino request fields, endpoint names, seat IDs, calibrated values
and expiry behaviour unless our change explicitly concerns one of them.
Keep the firmware unchanged for this task. Add no new dependencies.
First explain a short plan. After we agree it, implement only this change,
run relevant checks and explain changed files and anything you could not test.
Leave commit, push and Pi updating to our group.
```

After reading the plan, reply with a specific instruction such as: **Implement this plan. Keep the raw-reading display and the existing keyboard controls.** Review any tool permission request against the proposed action. Give corrections if the agent expands the task.

### Example: library interface prompt

```text
In host/index.html, add a text summary above the library map showing how many
of L1 and L2 are free, occupied and unknown. Use their current state values;
the ten decorative chairs must not contribute. Keep the individual raw readings.
If the host is unreachable, show that availability is unknown rather than
leaving a previous free count visible. Test occupied/free, stale and host-error
states. Change only the browser code; preserve the server and Arduino code.
Explain your plan first, then wait for our instruction to implement it.
```

### Example: ticket server prompt

```text
Improve startup validation of host/tickets.json in our existing ticket server.
Each entry needs a seat shown on our current map (A1–A4, B1–B4 or C1–C4)
and non-empty route text. For a bad entry, report the offending key and problem
clearly and stop startup. Preserve valid mappings and all existing HTTP routes.
Add relevant checks with a separate temporary mapping so our real card mapping
is not overwritten. Explain the plan first. After implementation, tell us which
cases you tested and what still needs a physical card test.
```

## 4. Review the change, then run it

Open **Review** from the conversation's Overview panel or changed-files card. Inspect the file differences: what was added, what was removed, and whether the change matches your card. Send a specific follow-up if needed: **The new total includes unmeasured chairs. Count only L1 and L2 and keep unknown separate from free.** The app supports comments on changed lines. [Review help](https://antigravity.google/docs/review-changes/).

Open a terminal in the app's side panel with **+ → Terminal** (`Ctrl+J` on Windows/Linux, `Cmd+J` on macOS). Check that it is at the project root, then use:

```bash
node --test host/test.js
node host/server.js
```

Open **http://localhost:3000** in a browser and perform your acceptance checks. Restart the local server after server changes; reload after interface changes. A second terminal can run `node host/simulate.js` for Group 1 or `node host/simulate.js ticket YOUR_UID` for Group 2. Stop the Group 1 simulator with Ctrl+C afterwards. Simulation checks the host and interface; it does not prove the physical input works. [App terminal and browser help](https://antigravity.google/docs/features/).

If the result is wrong, report the action, expected result, actual result and relevant error to the agent. Repeat review and the failed check after its correction. Keep baseline failures separate from failures caused by this change.

**Ready to publish:** the reviewer can explain the changed behaviour, the local checks are recorded and no unexplained file edits remain. Continue to [Activity 04](04-publish-update-and-test.md), then repeat this activity for the server card with a different driver.

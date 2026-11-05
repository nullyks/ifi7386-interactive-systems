# Activity 03 — Document the Project with AI

[Session 6](../README.md) · [Project record template](../templates/project-record.md) · [Next: hardware and BOM](04-hardware-and-bom.md)

**Time: 25 minutes · Use Antigravity's graphical desktop app on the development computer**

The aim is a useful project record, not a transcript of every class or AI conversation. Save the main decisions, evidence, versions and limitations. AI can organise supplied material and explain code; code alone cannot prove that a user study or hardware test happened.

## 1. Gather the evidence — about 5 minutes

Open your existing group development clone in Antigravity, using **Local mode**, as in [Session 5](../../05-ai-assisted-development-and-git-workflow/activities/03-develop-with-antigravity.md). Keep this computer connected to the internet; the Pi can stay on its group hotspot for testing. See [Antigravity projects](https://antigravity.google/docs/projects/).

Copy the [project record template](../templates/project-record.md) into `docs/project-record.md`. Add relevant notes/images to `docs/evidence/`, or link existing evidence that your team and assessor can access. Remove personal details from shared notes and screenshots. Do not copy whole private conversations or credentials into the repository or AI chat.

Use this list to find the main points across the course:

| Session | What to document | Useful existing evidence |
|---|---|---|
| 1 | Primary user, context, goal, initial problem/value hypothesis and assumptions | Concept statement, scenario, evidence notes and early prototype image |
| 2 | Architecture, main/alternative states, accessibility/ergonomics and prototype choice | Diagrams, review and walkthrough notes |
| 3 | What the Wizard-of-Oz study revealed; what became a realistic Arduino interaction | Tasks, observations, design implication and Hi-Fi build decision |
| 4 | How physical input reaches feedback; calibration or real test-tag mapping; failure/recovery | Wiring, Serial records, data contract and integrated test evidence |
| 5 | Chosen interface/server changes, the agent's role, review and delivery to the Pi | Change cards, selected prompt, diff/commits and physical test log |
| 6 | Peer-test results, design reasons, hardware/BOM and readiness gaps | Today's records and discussion |

Keep each milestone to a few sentences or a table row with links. If your project direction changed, preserve the earlier concept and explain the change. Record missing notes honestly; a dated recollection can be labelled **team recollection**, separately from an original observation.

## 2. Ask for an evidence inventory — about 5 minutes

Paste this into the app's conversation, replacing the source list with your actual files:

```text
We are documenting our existing IFI7386 team project across Sessions 1–6.
Read README.md, docs/project-record.md, our host and Arduino source,
relevant Git history, and ONLY these supplied evidence files: [paths].

Do not edit yet. List the available evidence for each session and the gaps.
Distinguish intended behaviour in code from an observed physical/user test.
Give a file/section or commit reference for each factual claim.
Do not infer participant results, hardware models, prices or uploaded firmware
versions from code or from a photograph. Mark missing evidence MISSING and
untested claims UNVERIFIED. Ask us at most three questions that matter most.
Do not modify code, sign-in settings or Git history, and do not commit or push.
```

Check the inventory and answer what you can. An evidence file may be incomplete or contradict another source; resolve this with the team rather than asking the agent to guess.

## 3. Draft, check and publish — about 15 minutes

```text
Use the evidence inventory we have checked to complete docs/project-record.md
and add documentation links to README.md. Keep existing startup instructions.
Edit only those two files. Leave hardware and BOM details for the next activity.

Use the template headings and concise tables. Cover all six sessions, two
implemented design changes, today's peer-test observations and one next decision.
Link each important claim to its supplied evidence or commit. Label planned
work PLANNED. Preserve failures, help given, uncertainty and missing evidence.
Do not invent quotations, measurements, test passes or completed activities.
Describe how we used AI and what our team checked or corrected.
At the end, list the remaining questions. Do not commit or push.
```

Open **Review** in the desktop app and inspect each changed file. A second team member compares claims with the originals, especially counts, quotations, versions, physical test results and the reasons for decisions. Ask the agent to correct any unsupported claim. [Antigravity Review instructions](https://antigravity.google/docs/review-changes/).

Preview the Markdown, then commit and push the reviewed documentation using the [Session 5 workflow](../../05-ai-assisted-development-and-git-workflow/activities/04-publish-update-and-test.md#1-commit-and-push-on-the-development-computer). Open it on GitHub and test the evidence links. If time runs out, keep explicit gaps and finish them after class.

Documentation-only edits do not require a Pi restart or an Arduino upload. Keep the earlier tested code version recorded; a new documentation commit is not a new hardware test.

**Output:** a readable, checked project record covering Sessions 1–6, with evidence links, an AI-use note and visible gaps.

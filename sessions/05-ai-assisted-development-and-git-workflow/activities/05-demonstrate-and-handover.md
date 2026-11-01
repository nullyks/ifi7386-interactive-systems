# Activity 05 — Demonstrate and Hand Over

[Session 5](../README.md) · [Update and test sequence](04-publish-update-and-test.md)

**Time: 10 minutes · About four minutes of demonstration and one minute of feedback per group**

## Show the workflow

1. Name the interface issue and server issue your group chose. Show the original observation and each requested result.
2. Show one prompt and one changed part of the code. Explain how your group checked the agent's work or corrected it.
3. Show the matching tested commit on GitHub and in the Pi clone. Explain when you use **TLU** and when you restore the **group hotspot**.
4. Demonstrate the two improvements on the Pi with physical input, including one relevant failure or recovery. Identify any part tested only with simulation.
5. State one remaining limitation and the next useful test. Each member explains a part of the loop.

## Keep a short test log

Save this in the team's shared notes, or commit it as `docs/test-log.md` from the development copy after testing. A later documentation-only commit may follow the code version tested on the Pi; keep that tested code commit explicitly recorded.

| Field | Round 1 — interface | Round 2 — server |
|---|---|---|
| Problem and requested result | | |
| Prompt or saved conversation link | | |
| Files changed and reviewer | | |
| Local check and result | | |
| Code commit pushed to GitHub | | |
| Same commit pulled on Pi | | |
| Pi switched to TLU, then back to group hotspot | | |
| Physical action and expected feedback | | |
| Actual result: PASS/FAIL, evidence | | |
| Original main-path regression check | | |
| Failure/recovery check and result | | |
| What the agent could not verify | | |

## Completion checklist

- The group owns a repository with its complete host and Arduino source folders, attribution and startup README.
- The development computer and Pi have separate clones of that repository.
- One interface improvement and one server improvement each went through review, local checks, commit, push, Pi pull, hotspot restoration and Pi testing.
- The driver changed between rounds; every member can explain save, commit, push, pull, restart and firmware upload.
- Test results distinguish real hardware, simulation, failures and unverified claims.

Before the next session, keep the README sufficient for another group member to restart the project: folder layout, Node command, sketch name, required libraries, group hotspot and Pi address. Preserve calibrated thresholds and actual ticket mappings. Bring one question about how a real user understands the updated feedback.

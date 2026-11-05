# Activity 02 — Find and Specify Improvements

[Session 5](../README.md) · [Previous activity](01-team-repository-and-two-clones.md) · [Next activity](03-develop-with-antigravity.md)

**Time:** 10 minutes · **Format:** choose one interface change and one server change

## Goal

Choose one interface issue and one server issue, each with a bounded change and an observable success condition.

## Observe first

Use the current page and read the relevant files. Try the main interaction and one waiting, unknown or error state. Ask what a user cannot understand or what a developer cannot diagnose. Record an actual observation before asking the agent for suggestions.

| File | Responsibility |
|---|---|
| `host/index.html` | Browser layout, text, SVG plan and displayed feedback. |
| `host/server.js` | HTTP routes, validation, stored state and expiry. |
| `host/test.js` | Existing automated checks; extend relevant checks when server behaviour changes. |
| `host/tickets.json` — Group 2 only | UID-to-seat mapping and written directions. |
| Network `.ino` sketch | Physical input and messages sent to the server. Read it to understand the contract. |

## Make two small change cards

| Field | Write before implementation |
|---|---|
| Observed problem | What happens now, and who has difficulty? |
| Desired behaviour | What should happen instead? |
| Scope | Which layer or files should change? |
| Acceptance check | Given this state/action, what exact result should we see? |
| Regression check | Which existing working interaction must still pass? |

Select an interface card for round 1 and a server card for round 2. Keep each small enough to implement and test in about twenty minutes. A different colour alone needs a reason connected to the user's task.

## Starting points if you need them

| Group | Possible interface improvement | Possible server improvement |
|---|---|---|
| 1 — Library | Show a readable count of free, occupied and unknown **sensor seats**; never count the decorative chairs as measured availability. | Add a summary to `GET /api/state`, calculated from the current, expiry-aware seat states. Counts must sum to two. |
| 2 — Ticket guidance | Make the next action clearer for a known ticket, unknown ticket, offline reader and host failure. Preserve the clear-display button and route removal. | Validate the ticket mapping at startup and explain an invalid seat ID or missing route with a clear message. Valid mappings must still work. |
| Either | Improve labels or the narrow-screen layout while keeping status text and keyboard access. | Handle a malformed request address with HTTP 400 and keep the server running. |

These are suggestions, not instructions to add every feature. Find your own issue if it has a clear test. Avoid replacing the application, introducing a new framework or adding accounts, databases and unrelated features.

For the library summary, a useful check is: **L1 occupied + L2 free → occupied 1, free 1, unknown 0; after both readings expire → unknown 2, free 0.** For ticket mapping, use a temporary invalid mapping for the negative test and restore the real one before delivery.

## Output

Two selected change cards with expected results. Your group chooses the change; the agent may help explain the code and refine the plan.

---

[Session 5](../README.md) · [Glossary](../../../resources/glossary.md) · [Readings and references](../../../resources/academic-readings.md)

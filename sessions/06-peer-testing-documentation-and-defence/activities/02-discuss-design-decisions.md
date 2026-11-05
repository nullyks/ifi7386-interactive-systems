# Activity 02 — Discuss Design Decisions

[Session 6](../README.md) · [Previous: cross-testing](01-prepare-and-cross-test.md) · [Next: AI documentation](03-document-the-project-with-ai.md)

**Time: 20 minutes · Discussion with the other team**

Use four minutes to select evidence, twelve minutes for a shared discussion and four minutes to record decisions. With two teams, give each team about six minutes of discussion. Show the earlier and current interface or interaction when possible.

## Explain two changes

Choose **two changes already made during the course**. Include at least one Session 5 change; the other can concern the concept, interaction, hardware, feedback or server behaviour. A server change also needs a reason connected to the user experience or system reliability.

For each, explain:

> We changed **[before]** to **[after]** because **[user need and evidence]**. We considered **[alternative]**, but chose this option because **[reason]**. Its trade-off is **[cost or limitation]**. We checked it with **[test and version]**, which showed **[actual result or UNVERIFIED]**.

Point to a concrete source: an observation, earlier prototype, code difference, calibration record or test result. “The AI suggested it” describes where an idea came from; explain why your team accepted it. If the reason was originally an assumption, say so.

## Discuss the result together

The visiting team first describes what it observed, then asks questions. The design team explains its reasons and can revise its interpretation.

- What user problem does this change address?
- What evidence supports the reason, and what remains an assumption?
- Which alternative did you consider, and what did you give up?
- Did the change help today's participant? What exact observation supports that?
- What happens when data, the host or the reader is unavailable?
- What would you test next with someone closer to the intended user?

## Decide what to do with today's finding

Select one finding from the peer test and choose **change**, **keep**, or **investigate first**. Record why, a proposed acceptance check, an owner and a next action. You do not have to implement the decision during this session.

| Decision | Evidence | Reason and trade-off | Verification / next check |
|---|---|---|---|
| Example only: replace a colour-only unknown state with text as well | P1's recorded interpretation of the unavailable-data state | More explicit meaning, with slightly more screen space | PLANNED: disconnect the board and ask a new participant what the status means |

Add the two completed changes and today's decision to the project record. Keep **implemented**, **tested** and **planned** separate. A failed test can support a useful design decision.

**Output:** two explained earlier changes and one reasoned next decision, with evidence and a verification status.

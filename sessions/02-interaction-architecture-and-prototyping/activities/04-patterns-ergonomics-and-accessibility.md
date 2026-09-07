# Activity 04 - Patterns, Ergonomics, and Accessibility

[← Session 2](../README.md) · [← Previous activity](03-states-and-alternative-interaction-paths.md) · [Glossary](../../../resources/glossary.md) · [Academic readings](../../../resources/academic-readings.md)

**Time:** 18 minutes · **Format:** structured team inspection

## Goal

Identify interaction, ergonomic, and accessibility risks before the team invests in a more detailed prototype.

## Part 1 - Interaction pattern

Select one recurring user problem in your flow. Complete:

> When **[situation or trigger]**, the user needs to **[goal]**, but **[recurring interaction problem]**. We propose **[pattern or response]** because **[reason grounded in the context]**.

Possible responses include visible system status, redundant feedback, confirmation, undo or recovery, consistent mapping, progressive disclosure, and a safe default. Name the problem before the response.

## Part 2 - Ergonomic inspection

Test the representation in the intended posture and approximate setting. Record one observation for each relevant dimension:

| Dimension | Inspection question |
|---|---|
| Perception | Can the signal be noticed and distinguished at the expected distance, angle, lighting, and noise level? |
| Action | Can the control be reached and operated with realistic movement, grip, and precision? |
| Mapping | Does the relationship between control, direction, state, and result match likely expectations? |
| Timing | Does feedback arrive soon enough to connect it with the action or event? |
| Error tolerance | Can a predictable mistake be prevented, corrected, reversed, or recovered from? |
| Workload | Does the interaction demand attention, memory, or coordination that the situation does not allow? |

## Part 3 - Accessibility inspection

Do not assume one sensory or motor channel works for everyone. Review the main and alternative paths.

1. **Meaning without one cue.** Remove colour, then sound, then fine visual detail. Which meaning disappears?
2. **Alternative operation.** Can a user complete the task without precise pointing, dragging, or one specific gesture?
3. **Status and errors.** Are state changes and problems expressed in words or another clear equivalent?
4. **Control identity.** For a digital control, is its name, role, value, and state clear enough to expose programmatically later?
5. **Target and spacing.** Are controls large and separated enough for the intended device and context?

For web content, connect findings to relevant WCAG 2.2 success criteria. Do not claim compliance from a paper inspection alone.

## Decision record

Record at least two changes:

| Finding | Affected user or context | Design change now | What still requires testing |
|---|---|---|---|
|  |  |  |  |
|  |  |  |  |

## Worked example

**Finding:** The three room states differ only by LED colour.

**Risk:** A user may not distinguish the colours, may view the indicator from an angle, or may not know the team's colour mapping.

**Change:** Add a short state label and distinct pulse pattern; keep the web status available to keyboard and assistive technology.

**Test question:** Can a first-time user identify the state and possible next action when colour is unavailable?

## Output

One justified interaction response, an ergonomic and accessibility review, and at least two concrete design changes or test questions.

## Public learning sources

- [ISO 9241-110:2020 official overview](https://www.iso.org/standard/75258.html)
- [ISO 9241-171:2025 official overview](https://www.iso.org/standard/86308.html)
- [W3C WCAG 2.2](https://www.w3.org/TR/WCAG22/)
- [van Welie and Trætteberg (2000), open paper](https://www.welie.com/papers/PLoP2k-Welie.pdf)

[Next activity →](05-prototype-fidelity-and-method-selection.md)

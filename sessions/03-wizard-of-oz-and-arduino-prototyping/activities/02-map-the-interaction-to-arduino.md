# Activity 02 - Map the Interaction to Arduino

[← Session 3](../README.md) · [← Previous activity](01-wizard-of-oz-study.md)

**Time:** 10 minutes · **Format:** short instructor demonstration and team mapping

## Goal

Connect one tested project interaction to a physical input, a rule, and an output.

## Steps

1. In your architecture, highlight one user or environment trigger and the first perceivable system response.
2. Name what the wizard simulated in that path: sensing, a decision, timing, output, or several parts.
3. Complete the map below. Use `unknown` where a component has not been chosen.

| Trigger or input | Arduino rule and state | Output and user feedback | External part or open question |
|---|---|---|---|
|  |  |  |  |

4. Circle the smallest part that could become realistic first. State why its realism matters to the user or to the next test.

## Example

`Button pressed → if system is ready, set active state → LED turns on and Serial Monitor says active.` The serial text helps the maker inspect behaviour; it is not automatically user-facing feedback.

## Output

One input → rule/state → output map and a candidate physical interaction to implement.

[Next activity →](03-first-upload-and-output.md)

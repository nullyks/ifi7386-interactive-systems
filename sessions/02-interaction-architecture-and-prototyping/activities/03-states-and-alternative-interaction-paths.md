# Activity 03 - States and Alternative Interaction Paths

[← Session 2](../README.md) · [← Previous activity](02-system-architecture-and-data-flow.md) · [Glossary](../../../resources/glossary.md) · [Academic readings](../../../resources/academic-readings.md)

**Time:** 18 minutes · **Format:** team state modelling and walkthrough

## Goal

Show how events and conditions change system state, then add alternative paths that expose recovery, missing feedback, or other important behaviour.

## Step 1 - Name the states

Use short conditions that can remain true for a period of time. For example:

- `comfortable`;
- `attention`;
- `action suggested`;
- `input unavailable`.

Avoid naming an event as a state. `Button pressed` is an event; `request registered` may be a state.

## Step 2 - Write the transitions

For each arrow, record:

```text
event or condition [optional guard] / system action and feedback
```

Example:

```text
comfort value remains above threshold for 60 seconds
  / set state to action suggested and update both outputs
```

## Step 3 - Add two alternative paths

Choose two alternatives that could affect the design:

1. an input is missing, late, repeated, or implausible;
2. the user does not perceive or understand the feedback;
3. the user cancels, reverses, waits, or repeats an action;
4. power, connection, or an external service becomes unavailable;
5. two people act at nearly the same time;
6. the system needs a timeout, recovery, or safe default.

For each alternative, show:

- the trigger;
- what the system can know;
- the state change or decision;
- perceivable feedback;
- the user's available next action;
- how the interaction returns to a known state.

## Step 4 - Cross-check the architecture

Trace the main and alternative paths across the architecture diagram. Add a missing component or flow only when the state model shows why it is needed.

## Worked example

**Alternative:** The simulated sensor value does not update.

```text
comfortable
  + no new value for the agreed interval
  → mark input unavailable
  → show “Status unavailable” without a comfort recommendation
  → input unavailable
```

The user can still understand the limitation. The system does not silently present an old value as current.

## Output

One main state path, at least two alternative paths, and a marked correction to the architecture or prototype requirements.

## Public learning sources

- [Harel (1987), open university-hosted PDF](https://www.csd.uoc.gr/~hy565/docs/pdfs/papers/statecharts_visual_formalism.pdf)
- [MIT, open reading on input events and state machines](https://web.mit.edu/6.813/www/sp17/classes/12-input/)

[Next activity →](04-patterns-ergonomics-and-accessibility.md)

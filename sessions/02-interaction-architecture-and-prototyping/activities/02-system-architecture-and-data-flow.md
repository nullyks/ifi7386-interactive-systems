# Activity 02 - System Architecture and Data Flow

[← Session 2](../README.md) · [← Previous activity](01-evidence-and-concept-reconnect.md) · [Glossary](../../../resources/glossary.md) · [Academic readings](../../../resources/academic-readings.md)

**Time:** 20 minutes · **Format:** team modelling and instructor checkpoint

## Goal

Create an initial system architecture that makes responsibilities, boundaries, and data flows visible without pretending that implementation decisions are final.

## Materials

Use a large sheet, sticky notes, or a shared diagram. Use boxes for parts and labelled arrows for flows. Keep every label readable from across the table.

> [!TIP]
> For a visual example, see Bentley University's [Process Modeling: Data Flow Diagrams](https://cis.bentley.edu/lwaguespack/CS360_2020_slides/CS360Unit04DFD.pdf). Pages 5 and 13–16 show common diagram elements, a system boundary, external entities, processes, a data store, and labelled flows. Use the visual logic as guidance; this activity does not require formal DFD notation.

## Required parts

Include only parts that affect the main interaction:

- user and relevant environment;
- physical and digital interfaces;
- input source or sensor;
- processing, control, or decision logic;
- current state or stored data;
- output or actuator;
- external service or person if the concept depends on one.

## Steps

1. **Set the boundary - 3 minutes.** Draw one boundary around what your team proposes to build. Put users, environmental events, and external services outside it.
2. **Assign responsibilities - 5 minutes.** Add components as boxes. Give each one a short responsibility, not a product name.
3. **Label the flows - 6 minutes.** Add arrows and label the event, value, command, message, or stored data that moves.
4. **Trace one vertical slice - 4 minutes.** Follow one complete path from trigger through feedback and the user's next action.
5. **Checkpoint - 2 minutes.** Ask another member to explain the diagram without help from its author.

## Flow label test

Replace vague labels such as `information`, `data`, `signal`, or `response` with the actual content:

| Vague | More useful |
|---|---|
| data | room-comfort value and timestamp |
| signal | button-pressed event |
| response | actuator command set to pulse |
| status | current state and recommended action |

## Worked example

```text
room condition
  → simulated sensor input: comfort value
  → threshold and persistence rule
  → current state: comfortable / attention / action suggested
  → physical indicator command + web status message
  → student perceives label and signal
  → student decides whether to ventilate or continue
```

The first low-fidelity model may use a person to provide the simulated value and change the outputs. The architecture should still show the proposed future responsibilities so the team can distinguish simulated behaviour from intended implementation.

## Check the model

- Does every component have one understandable responsibility?
- Is every arrow labelled with what actually crosses the boundary?
- Where is the current state kept?
- Which flow becomes feedback the user can perceive?
- Which dependency would stop the main scenario if it failed?
- Does the diagram include anything that is not needed for the main scenario?

## Output

Architecture and labelled data-flow diagram version 1, plus one dependency or uncertainty to revisit.

## Public learning sources

- [ISO/IEC/IEEE 42010:2022 official overview](https://www.iso.org/standard/74393.html)
- [Fielding (2000), open chapter on software architecture](https://ics.uci.edu/~fielding/pubs/dissertation/software_arch.htm)

[Next activity →](03-states-and-alternative-interaction-paths.md)

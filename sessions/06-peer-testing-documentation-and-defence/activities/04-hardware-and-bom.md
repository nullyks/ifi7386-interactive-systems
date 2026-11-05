# Activity 04 — Hardware and BOM

[Session 6](../README.md) · [Worked library example](../examples/library-hardware-and-bom.md) · [Next: defence rehearsal](05-defence-rehearsal.md)

**Time: 25 minutes · Inspect the actual build, then use AI to draft its record**

A **bill of materials (BOM)** lists the physical parts and quantities needed for a particular build. The hardware record explains how those parts are connected and used. Give the same part IDs to the items in the BOM, diagram and photographs so another person can match them. See [OSHWA's documentation and BOM guidance](https://oshwa.org/resources/sharing-best-practices/).

## 1. Inspect and identify — about 5 minutes

Copy the [hardware template](../templates/hardware.md) to `docs/hardware.md` and [CSV header](../templates/bom.csv) to `docs/bom.csv` in your development clone. Open CSV as text in the editor; a spreadsheet application is optional.

With the circuit powered off, inspect labels and existing connections. Record:

- board and sensor/reader model, resistor values and actual quantities;
- pin-to-pin connections, supply voltage and power source;
- mounting, dimensions that matter, strain relief and calibration or test-tag setup;
- the Pi, power supplies, storage, cables and display equipment needed to run the demonstration.

Take an overview photo and a readable close-up of connections. Use IDs such as `U1`, `S1`, `R1` and `P1`. Record a hardware revision such as `HW-01` and the date. Mark an unreadable model or uncounted wire quantity **UNVERIFIED**. Use the existing wiring guide; this activity documents the build rather than requiring rewiring.

## 2. Try the worked example — about 5 minutes

Open the [two-chair library example](../examples/library-hardware-and-bom.md). Compare its connection table, simple diagram and [example CSV](../examples/library-bom.csv). Notice that two FSRs require **two** separate divider resistors, while their exact sensor models and jumper count still require inspection.

The example includes a deliberately incomplete inventory. Identify one missing fact and how you would verify it. Then use the same method for your own group. Group 2 follows its [RC522 classroom wiring guide](../../04-integration-and-collaborative-development/group-2-ticket.md#parts-and-wiring), including **3.3 V reader power**, actual reader model and test tags; do not copy the FSR circuit into the ticket project.

## 3. Ask the agent for a draft — about 8 minutes

Supply your actual inspection notes, wiring guide and code paths in Antigravity:

```text
Document the hardware we actually built. Use only [inspection notes],
[labelled photos], [our wiring guide] and [our actual sketch path].
Our hardware revision is [HW-01], inspected on [date].

Edit only docs/hardware.md and docs/bom.csv, using their templates.
Describe power, pin connections, mounting, calibration/mapping, a simple
verification procedure and limitations. Match part IDs across both files.
Create a small Mermaid connection diagram from the checked wiring notes.

For each BOM row include ID, item, quantity, unit, specification, role,
evidence/source, unit_price_eur and status. Separate prototype parts from
required demonstration equipment. Count borrowed equipment too and label it.
If a quantity or price is unknown, leave its numeric cell empty and explain
the gap in status. Do not invent a model, voltage, quantity, supplier or price.
Do not treat a photo as proof of hidden wiring or resistor values.
Flag any conflict between notes, photo and code for us to inspect.
Do not alter code, wiring or Git history. Do not commit or push.
```

## 4. Check and share — about 7 minutes

One member checks the draft against the powered-off physical build; another checks the sketch and BOM. Confirm voltages and exact pins from labels and the group guide. Then power up the unchanged build and run one known input-to-feedback check. Record the actual outcome or **NOT RUN**; drafting the instructions does not count as running them.

Do not copy example calibration thresholds as measured values. In the library project, record each chair's actual empty/occupied measurements and ON/OFF settings. In the ticket project, record compatible test tags and the host mapping, with no personal ticket data. If the uploaded firmware source is unknown, keep that gap visible and arrange a controlled upload/retest later.

Prices are optional in this lesson. An unknown price is **not €0**. If you add costs, include a real supplier/source and quote date; say whether tax, shipping and required equipment are included. Label a sum that omits unpriced rows as a **partial known-cost subtotal**.

Review and push the two documentation files and approved evidence images. Keep previous hardware revisions or describe changes when the build changes.

**Output:** a checked hardware record and BOM for the current build, with matching IDs, clear power/wiring, evidence and explicit unknowns.

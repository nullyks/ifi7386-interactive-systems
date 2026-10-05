# Session 3 - Wizard-of-Oz Study and Arduino Prototyping

[Course home](../../README.md) · [All sessions](../README.md) · [Glossary](../../resources/glossary.md) · [Academic readings](../../resources/academic-readings.md)

**Duration:** 135 minutes in three 45-minute blocks · **Working language:** English · **Equipment:** one Arduino kit per student; work individually, in pairs, or in project teams

> [!NOTE]
> Begin with the Wizard-of-Oz study prepared after Session 2. Keep the participant task, operator script, and observation record separate. After the study, follow the Arduino exercises in order. A team may share a circuit, but every member should be able to explain its input, rule, and output.

## Where we are going

First, use your low-fidelity prototype with a participant and learn where the interaction succeeds or breaks down. Then get a working Arduino input-to-output loop and explore which parts of your project could become a **high-fidelity (Hi-Fi) prototype** on Arduino. Here, Hi-Fi means realistic behaviour in the selected physical interaction; it does not mean that every part of the system must be finished.

By the end of the meeting, you can:

- run a repeatable Wizard-of-Oz task and separate observation from interpretation;
- upload and change an Arduino sketch, identify the board and port, and use Serial Monitor;
- explain digital input, a control rule, and digital output through a working button-to-LED circuit;
- identify a suitable sensor or actuator path for one part of your project and its power or integration constraints;
- name a small Arduino-based Hi-Fi slice, a first test, and what will remain simulated.

## Session route

| Minutes | Focus | Open in class | Team result |
|---|---|---|---|
| 0–35 | Wizard-of-Oz study and evidence | [Activity 01](activities/01-wizard-of-oz-study.md) | Observation record and one design implication |
| 35–45 | Transition from simulated to implemented behaviour | [Activity 02](activities/02-map-the-interaction-to-arduino.md) | Input → rule → output map |
| 45–70 | Board, sketch, upload, and first output | [Activity 03](activities/03-first-upload-and-output.md) | Working on-board Blink and checked board/port |
| 70–100 | Button input and LED feedback | [Activity 04](activities/04-button-to-led-loop.md) | Working physical interaction and Serial Monitor evidence |
| 100–120 | Sensor and motor options | [Activity 05](activities/05-component-stations.md) | Feasibility notes for the project |
| 120–135 | Choose the Hi-Fi slice | [Activity 06](activities/06-hifi-slice-and-handover.md) | Build decision and next-session preparation |

## Key terms for today

| Term | Simple meaning |
|---|---|
| **Wizard-of-Oz** | A person produces behaviour that a future system may automate |
| **Observation** | What the participant did or said, without a claim about why |
| **Sketch** | An Arduino program with `setup()` and a repeating `loop()` |
| **Digital input** | A read value with two logical states, `HIGH` or `LOW` |
| **Analog input** | A measured value across a range, often used with a sensor |
| **Output** | A signal from the board that changes light, sound, movement, or another device |
| **Serial Monitor** | A text view for checking values and program behaviour over USB |
| **Actuator** | A component that produces physical action, such as a motor |
| **Driver** | Electronics that let a low-current control signal switch a larger load |
| **Hi-Fi slice** | One selected interaction whose important physical behaviour is implemented realistically |

## 1. Run the Wizard-of-Oz study first

Use the research question, two task scenarios, and operator script prepared for this meeting. Tell the participant enough to give informed consent and explain any recording; avoid claiming the prototype is automated if that would mislead them about a material risk. The operator follows the written rules and timing. The observer records actions and statements before the team discusses causes. Debrief the participant about simulated behaviour after the task.

**Do now:** [Activity 01 - Wizard-of-Oz Study](activities/01-wizard-of-oz-study.md)

## 2. Translate the interaction into an Arduino loop

Mark the parts of your current architecture that receive input, apply a rule, hold state, and produce user feedback. An Arduino UNO can read switches and many sensors, run a local rule, and control modest outputs. A connected computer, phone app, network service, or heavy actuator may need additional hardware or remain simulated for now.

```text
person or environment → input → Arduino rule and state → visible, audible, or moving output → person's next action
```

The board is a tool for implementing the selected behaviour, not a reason to change the user problem. Choose the smallest path that matters to the user and that the available kit can safely demonstrate.

**Do now:** [Activity 02 - Map the Interaction to Arduino](activities/02-map-the-interaction-to-arduino.md)

## 3. Get a sketch running

Identify your UNO model and matching USB data cable. In Arduino IDE, select the board and port, open the built-in Blink example, upload it, and change the blink interval. If upload fails, check the selected board, port, cable, and whether another program has the serial port open. The on-board LED lets you verify the upload before adding wires.

**Do now:** [Activity 03 - First Upload and Output](activities/03-first-upload-and-output.md)

### Source route

- [Arduino introduction: IDE setup](https://github.com/nullyks/Arduino-sissejuhatus/blob/main/materjalid/1_Tarkvara_paigaldamine_ja_seadistamine.md)
- [Arduino introduction: connection and upload](https://github.com/nullyks/Arduino-sissejuhatus/blob/main/materjalid/2_%C3%9Chendamine_ja_%C3%BCleslaadimine.md)
- [Arduino introduction: UNO pins](https://github.com/nullyks/Arduino-sissejuhatus/blob/main/materjalid/3_Arduino_UNO_viigud.md)

## 4. Build one complete physical interaction

Connect a pushbutton between digital pin 3 and GND. Configure the pin as `INPUT_PULLUP`: unpressed reads `HIGH`; pressed reads `LOW`. Then connect an LED through a **470 Ω series resistor** to a suitable output pin and GND. Start by making the LED show the button state. Open Serial Monitor to see the read value or a short status message. Change only one thing at a time and explain the observed effect.

Disconnect the USB cable before changing wiring. Check LED polarity and avoid a direct connection between 5 V and GND. The course source recommends 470 Ω for physical LED circuits compatible with UNO R3 and UNO R4 WiFi; the older Tinkercad diagram uses 220 Ω, so follow the 470 Ω value for physical work.

**Do now:** [Activity 04 - Button to LED Loop](activities/04-button-to-led-loop.md)

### Source route

- [Button input and `INPUT_PULLUP`](https://github.com/nullyks/Arduino-sissejuhatus/blob/main/materjalid/4_Nupu_lugemine.md)
- [LED control and PWM](https://github.com/nullyks/Arduino-sissejuhatus/blob/main/materjalid/5_LED_juhtimine.md)

## 5. Explore sensor and movement options

Use the component examples as design choices. You do not need to build every circuit today. For sensing, compare the event or physical quantity your project needs with the available examples: force or bend, temperature, distance, motion, humidity, and soil moisture. Ask whether the reading is direct enough for the user claim, whether it needs calibration, and what a missing or noisy value should cause.

For movement, choose the required physical behaviour first. A servo targets an angle; a DC motor turns continuously and may need speed or direction control; a stepper moves in controlled steps. **Do not power a motor directly from an Arduino I/O pin.** Motor work requires a suitable driver, separate power where specified, correct voltage and current, and common ground. During this introduction, use the motor material to plan or inspect an instructor-prepared setup; wire a motor only with appropriate parts and supervision.

**Do now:** [Activity 05 - Component Stations](activities/05-component-stations.md)

### Source route

- [Arduino sensors: overview and component lessons](https://github.com/nullyks/Arduino-erinevad-andurid)
- [Arduino motors and power: overview and component lessons](https://github.com/nullyks/Arduino-mootorid-ja-toide)

## 6. Select a Hi-Fi slice for your project

Return to the Wizard-of-Oz evidence. Select one interaction that would benefit from realistic sensing, timing, feedback, or movement. Describe what Arduino can implement, what other parts are needed, what remains simulated, and what a successful bench test would show. Keep the planned slice consistent with the architecture and state model.

**Do now:** [Activity 06 - Hi-Fi Slice and Handover](activities/06-hifi-slice-and-handover.md)

## 7. Prepare for Session 4

Bring a one-page build decision with: the user action or environmental trigger; input component and pin or interface; decision rule and state; output component; power and safety needs; expected feedback and recovery; one simple test; component availability; and parts that stay simulated. Include a revised architecture or interaction path if today's evidence changed it. You may bring a working Arduino sketch, but a justified and buildable plan is the minimum handover.

---

[Previous session](../02-interaction-architecture-and-prototyping/README.md) · [Open Activity 01](activities/01-wizard-of-oz-study.md) · [Academic readings](../../resources/academic-readings.md)

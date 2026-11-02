# Course glossary

[Course home](../README.md) · [All sessions](../sessions/README.md) · [Readings and technical references](academic-readings.md)

Key terms from **Sessions 1–5**, grouped by topic. Each bold term has a short meaning and a course example. Use this as a reference while working; the examples include the study-room concept, both integrated group projects and the AI-assisted Git workflow.

## Find a topic

- [People, goals, and context](#people-goals-and-context)
- [Claims and evidence](#claims-and-evidence)
- [Interaction](#interaction)
- [Design concepts](#design-concepts)
- [Arduino, sensing, and firmware](#arduino-sensing-and-firmware)
- [Networking and integration](#networking-and-integration)
- [Git and shared code](#git-and-shared-code)
- [AI-assisted development and testing](#ai-assisted-development-and-testing)
- [Safety and scope](#safety-and-scope)

## Find terms for your session

| Session | Start with |
|---|---|
| [1 — User needs and concept](../sessions/01-user-needs-and-initial-project-concept/README.md) | [People and context](#people-goals-and-context), [evidence](#claims-and-evidence), [interaction](#interaction) and [design concepts](#design-concepts). |
| [2 — Architecture and prototyping](../sessions/02-interaction-architecture-and-prototyping/README.md) | [Interaction and architecture](#interaction), [design concepts](#design-concepts), [study terms](#claims-and-evidence). |
| [3 — Wizard-of-Oz and Arduino](../sessions/03-wizard-of-oz-and-arduino-prototyping/README.md) | [Study terms](#claims-and-evidence), [Hi-Fi slice](#hi-fi-slice), [Arduino and firmware](#arduino-sensing-and-firmware). |
| [4 — Integration](../sessions/04-integration-and-collaborative-development/README.md) | [Sensors and calibration](#arduino-sensing-and-firmware), [networking and integration](#networking-and-integration), [testing](#ai-assisted-development-and-testing). |
| [5 — AI-assisted Git workflow](../sessions/05-ai-assisted-development-and-git-workflow/README.md) | [Git and shared code](#git-and-shared-code), [AI development and testing](#ai-assisted-development-and-testing), [firmware upload](#firmware-upload). |

## People, goals, and context

| Term | Meaning | Course example |
|---|---|---|
| <a id="user"></a>**User** | A person who directly or indirectly interacts with a system. | A student who sees a room-status cue and decides whether to open a window. |
| <a id="primary-user"></a>**Primary user** | The main user in the scenario your team is designing. A project can affect several people, but the first concept should name one clear primary user. | A student taking part in a long group-work session. |
| <a id="user-goal"></a>**User goal** | What the user wants or needs to achieve. A goal is not the same as a system feature. | Continue focused group work in a comfortable room. “Use a CO₂ sensor” is not a user goal. |
| <a id="context-of-use"></a>**Context of use** | The conditions around an interaction. Context includes the user, goal, task, place, social situation, organisation, available technology, and other constraints. | A bookable study room, a group working together, limited ventilation, shared responsibility, and people who do not all face the same direction. |
| <a id="constraint"></a>**Constraint** | A condition that limits the design or affects whether it works. | The cue must be visible but should not interrupt a discussion. |
| <a id="stakeholder"></a>**Stakeholder** | A person or group affected by the project or able to affect it. A stakeholder is not always the primary user. | Students are primary users of the room cue. University facilities staff may also be stakeholders. |
| <a id="workaround"></a>**Workaround** | What a person currently does to manage a problem when there is no good direct solution. | A student opens a window based only on personal judgement because the group has no shared way to discuss room comfort. |
| <a id="psychological-safety"></a>**Psychological safety** | A shared feeling that team members can ask questions, challenge ideas, make mistakes, and admit uncertainty without being embarrassed or punished. | A teammate can admit uncertainty about wiring and ask for help. |

## Claims and evidence

| Term | Meaning | Course example |
|---|---|---|
| <a id="hypothesis"></a>**Hypothesis** | An idea or claim that may be true but has not yet been confirmed. A hypothesis should be checked with evidence. | Students may notice poor room comfort too late. |
| <a id="evidence"></a>**Evidence** | Information that helps you judge a claim. Evidence may come from a trustworthy source, observation, conversation, test, or measurement. | Two students describe when they notice discomfort and what their groups usually do. |
| <a id="assumption"></a>**Assumption** | Something the team currently treats as true without enough evidence. | The team assumes that everyone will understand a blue light as “comfortable.” |
| <a id="interpretation"></a>**Interpretation** | What the team thinks an observation or statement may mean. An interpretation is not the same as the original evidence. | A participant says nobody wants to interrupt the group. The team interprets this as a possible problem of shared responsibility. |
| <a id="anonymised-evidence"></a>**Anonymised evidence** | Evidence from which identifying details have been removed. Another reader should not be able to identify the participant from the notes. | Write “Participant 1, student using a group room,” not the person's name or contact details. |
| <a id="observation"></a>**Observation** | What a participant did or said, recorded separately from the team’s explanation of why it happened. | A participant scans twice before looking at the route. |
| <a id="research-question"></a>**Research question** | The specific uncertainty a study is intended to investigate. | Can a first-time visitor understand where to go without spoken help? |
| <a id="participant-task"></a>**Participant task** | A situation and goal given to a participant, without teaching the required interface actions. | Find the seat assigned to your ticket. |
| <a id="operator-script"></a>**Operator script** | Rules and timing followed by the person simulating a system in a Wizard-of-Oz study. | Change the status card only after the agreed trigger. |
| <a id="informed-consent"></a>**Informed consent** | Voluntary agreement to participate after an understandable explanation of the study and any recording. | Explain the task and recording before the participant starts. |
| <a id="debrief"></a>**Debrief** | An explanation after the study of what was simulated and how the evidence will be used. | Explain that a person, rather than a sensor, changed the prototype’s display. |

## Interaction

| Term | Meaning | Course example |
|---|---|---|
| <a id="interactive-system"></a>**Interactive system** | A system that receives input, changes or responds, and gives output that affects what a person understands or does next. It does not need to have a screen. | A bus stop-request system receives a button press, changes state, and gives sound and visual feedback. |
| <a id="input"></a>**Input** | An action, signal, or change in the environment that enters the system. | A button press or a value from a sensor. |
| <a id="system-state"></a>**System state** | What the system currently knows, stores, or treats as true. | The room status is “Comfortable” or “Action suggested.” |
| <a id="output"></a>**Output** | What the system produces or changes in the physical or digital world. | A light changes and a web page shows a new message. |
| <a id="feedback"></a>**Feedback** | Output that helps the user understand what happened, what the system is doing, or what to do next. | The label “Open window or take a short break” explains the meaning of the changed status. |
| <a id="interface"></a>**Interface** | Everything through which the user and system communicate. An interface can include controls, screens, sound, light, movement, sensors, and physical objects. | A labelled physical indicator and a simple web-status page. |
| <a id="interaction-loop"></a>**Interaction loop** | The connected sequence from a user's goal and action to system input, state change, output, feedback, and the user's next action. | A ticket scan produces a route, which the visitor interprets and follows. |
| <a id="system-boundary"></a>**System boundary** | The line between what the system does and what happens outside it. Defining the boundary helps the team decide what the first version must include. | The system receives a sensor value and changes a status. Opening the window is an action outside the system. |
| <a id="system-architecture"></a>**System architecture** | A purposeful description of the system's main parts, their responsibilities, and their relationships. A course architecture diagram does not need to show every implementation detail. | Arduino reads a tag; the Pi maps its UID; the browser displays the destination. |
| <a id="component"></a>**Component** | A part of the system with a named responsibility. | The input component receives a room-comfort value; the control component applies the current rule; the output component updates the physical indicator. |
| <a id="data-flow"></a>**Data flow** | An event, value, command, message, or stored item that moves between components or across the system boundary. | A comfort value moves from the simulated input to the state rule. A labelled status message moves from the system to the web interface. |
| <a id="event"></a>**Event** | Something that happens at a particular time and may trigger system behaviour. | A user presses a button, a new sensor value arrives, or a timeout expires. |
| <a id="transition"></a>**Transition** | A change from one system state to another caused by an event or condition. | Fresh seat data becomes unknown when its timeout is exceeded. |
| <a id="guard-condition"></a>**Guard condition** | A condition that must be true before a transition can occur. | The status changes only if the comfort value remains above the threshold for the agreed interval. |
| <a id="alternative-interaction-path"></a>**Alternative interaction path** | A meaningful route other than the expected main scenario, such as cancellation, repeated input, missing feedback, timeout, or recovery. | An unknown ticket gives a helpful message and removes the previous route. |
| <a id="threshold"></a>**Threshold** | A value or condition that causes a system to change state. | The status changes when a simulated sensor value goes above an initial threshold. |

## Design concepts

| Term | Meaning | Course example |
|---|---|---|
| <a id="human-centred-design"></a>**Human-centred design** | An approach that keeps people, their goals, tasks, abilities, and contexts central throughout design and development. Teams involve users, use evidence, evaluate ideas, and improve them through repeated cycles. | Use participant evidence to revise the concept before adding features. |
| <a id="value-proposition"></a>**Value proposition** | A short claim about how a concept may help a specific user in a specific context. It describes a human benefit, not a list of product features. | A calm cue may help a student group decide when to ventilate without repeatedly checking raw data. |
| <a id="use-scenario"></a>**Use scenario** | A short and concrete story showing how one interaction happens from trigger to outcome. | The room status changes, a student notices the cue, the group opens a window, and the status later returns to comfortable. |
| <a id="prototype"></a>**Prototype** | A representation made to explore or test a design question. A prototype is not the finished product. | Movable state cards can test whether people understand three different room-status messages. |
| <a id="low-fidelity-prototype"></a>**Low-fidelity prototype** | A deliberately simple, quick-to-change prototype representing only the qualities needed for the current design question. Low fidelity is not a judgement of design quality. | Paper screens, cardboard, sticky notes, or a person changing state cards. |
| <a id="prototype-question"></a>**Prototype question** | The specific question a prototype should help answer. | Can a first-time user understand the state change without spoken help? |
| <a id="wizard-of-oz-prototype"></a>**Wizard-of-Oz prototype** | A prototype in which a person secretly or openly performs a system action that is not yet automated. | A team member changes the room-status card when a simulated sensor value crosses a threshold. |
| <a id="fidelity"></a>**Fidelity** | How closely a prototype represents selected qualities of the intended system. Fidelity can differ across appearance, behaviour, timing, physical form, data, and technical implementation. | Use paper to test label meaning, then real sensor timing when that matters. |
| <a id="interaction-pattern"></a>**Interaction pattern** | A reusable design response to a recurring interaction problem. A pattern must be selected for a stated problem and context rather than copied automatically. | Show clear system status while waiting for a reading. |
| <a id="ergonomics"></a>**Ergonomics** | The study and design of interactions between people and other parts of a system. In this course, ergonomic review includes perception, reach, movement, posture, mapping, workload, timing, and use errors in the intended context. | Check button reach and display visibility in the intended setting. |
| <a id="accessibility"></a>**Accessibility** | The extent to which people with a wide range of abilities and needs can use a product, system, service, environment, or facility to achieve their goals in the intended context. | Provide readable status text as well as colour, and keyboard access to controls. |
| <a id="iteration"></a>**Iteration** | A repeated cycle of learning, changing the design, and testing again. | Revise feedback after a walkthrough and test the changed version again. |
| <a id="peer-feedback"></a>**Peer feedback** | Focused comments from students of similar status. Good peer feedback explains what was understood, what was unclear, which assumption may be risky, and what question should be investigated next. | Another team identifies unclear feedback and suggests a focused next test. |
| <a id="criterion-and-criteria"></a>**Criterion and criteria** | A **criterion** is one question or standard used to judge an idea. **Criteria** is the plural form. | User access, safety, and feasibility are three criteria for comparing project ideas. |
| <a id="high-fidelity-prototype"></a>**High-fidelity prototype** | A prototype with realistic qualities needed for a particular test, such as physical behaviour, timing or feedback. It need not be a complete or polished product. | Real sensor input changes the browser’s seat feedback. |
| <a id="hi-fi-slice"></a>**Hi-Fi slice** | One selected interaction implemented with the realism needed to investigate a project question. Other parts may remain simulated. | An actual button press produces the intended physical feedback. |

## Arduino, sensing, and firmware

| Term | Meaning | Course example |
|---|---|---|
| <a id="arduino-ide"></a>**Arduino IDE** | The development application used here to select the board and USB port, compile a sketch and upload it to the Arduino. | Use it on the development computer for the USB upload. |
| <a id="sketch"></a>**Sketch** | An Arduino program, usually saved as an `.ino` file, with `setup()` and a repeating `loop()`. | Keep `library.ino` inside its `library/` folder. |
| <a id="firmware"></a>**Firmware** | Embedded software that controls a device’s behaviour. Here this usually means the compiled Arduino sketch; the Wi-Fi connectivity module has separate firmware. | The `.ino` source is stored in GitHub; its compiled program runs on Arduino. |
| <a id="compile--verify"></a>**Compile / Verify** | Translate source code into a program for the selected board and report build errors. Successful compilation does not prove the wiring or interaction works. | Arduino IDE’s Verify checks that the sketch builds. |
| <a id="firmware-upload"></a>**Firmware upload** | Install the compiled sketch on the Arduino over USB from the development computer. This is separate from a GitHub push. | Select UNO R4 WiFi and its USB port, then choose Upload. |
| <a id="serial-monitor"></a>**Serial Monitor** | A text view for inspecting Arduino values and messages over USB, using the speed selected in the sketch. | Session 3’s button example uses 9600; Session 4’s sketches use 115200. |
| <a id="digital-input"></a>**Digital input** | An input read as one of two logical states, `HIGH` or `LOW`. Their meaning depends on the circuit. | The course pull-up button reads `LOW` when pressed. |
| <a id="analog-input"></a>**Analog input** | An input that measures a voltage across a range and converts it to a numeric reading. | The chair sketches explicitly use 10-bit readings, from 0 to 1023. |
| <a id="pull-up-input"></a>**Pull-up input** | An input held high through a resistor until a connected action pulls it low. `INPUT_PULLUP` enables the board’s internal pull-up. | The Session 3 button connects the input pin to GND when pressed. |
| <a id="debounce"></a>**Debounce** | A rule that filters rapid changes caused by mechanical switch bounce. | A press counter should not count one physical press several times. |
| <a id="sensor"></a>**Sensor** | A component that produces a signal related to a physical condition or event. A reading requires interpretation. | An FSR detects pressure; it does not prove a person is sitting. |
| <a id="actuator"></a>**Actuator** | A component that produces physical action from a control signal. | A motor moves part of a prototype. |
| <a id="driver"></a>**Driver** | Electronics that allow a control signal to switch or regulate a load that a board pin cannot power directly. | A suitable motor driver controls a motor with its required supply. |
| <a id="fsr"></a>**FSR** | Force-sensitive resistor: a sensor whose resistance changes with applied force. | Group 1 uses an FSR and resistor as a voltage divider for each chair. |
| <a id="rfid-and-uid"></a>**RFID and UID** | RFID identifies compatible tags by radio. A UID is the identifier read from a tag; UID matching here is not secure authentication. | Group 2 maps an actual tag UID to a seat and written route. |
| <a id="raw-reading"></a>**Raw reading** | A measured numeric value before it is interpreted as a user-facing state. It may already have been smoothed by the sketch. | `raw: 700` and `occupied: true` describe different things. |
| <a id="calibration"></a>**Calibration** | Use measurements from the actual mounted setup to choose appropriate settings or interpret readings. | Measure empty and occupied readings separately for L1 and L2. |
| <a id="hysteresis"></a>**Hysteresis** | Use different thresholds for entering and leaving a state, keeping the previous state between them. | A chair becomes occupied above ON and free below OFF. |

## Networking and integration

| Term | Meaning | Course example |
|---|---|---|
| <a id="client"></a>**Client** | A program or device that sends a request to a server. Its role depends on the architecture. | In Sessions 4–5, both Arduino and the browser request services from the Pi. |
| <a id="server"></a>**Server** | A program that handles requests and returns responses. It is not necessarily a separate kind of computer. | Sessions 4–5 run a Node.js server on the Pi 400. |
| <a id="nodejs"></a>**Node.js** | The JavaScript runtime used to run the supplied server outside the browser. | Start `node host/server.js` on the Pi. |
| <a id="http"></a>**HTTP** | The request/response protocol used here between clients and the server. | Arduino sends a reading; the server returns an acceptance or error response. |
| <a id="get-and-post"></a>**GET and POST** | HTTP methods: GET requests a representation; POST submits data for the server to process. | The browser GETs `/api/state`; Group 1 POSTs readings to `/api/seats`. |
| <a id="endpoint"></a>**Endpoint** | An API destination identified here by an HTTP method and path. | `POST /api/ticket` accepts Group 2 ticket events. |
| <a id="json"></a>**JSON** | A text format for structured values, including objects, arrays, numbers, strings and booleans. | `{"v":1,"ready":true}` uses a number and an unquoted boolean. |
| <a id="data-contract"></a>**Data contract** | The agreed message fields, types, IDs and meanings exchanged between components. | The chair request needs version 1, known seat IDs, boolean occupancy and integer readings. |
| <a id="validation"></a>**Validation** | Check a request against the contract before accepting it or changing stored state. | Reject an unknown chair ID or a string where a boolean is required. |
| <a id="http-status-code"></a>**HTTP status code** | A number describing the outcome of a request. Acceptance is not proof of correct user feedback. | 200 means the host accepted the message; still check the correct seat on screen. |
| <a id="wi-fi-hotspot--access-point"></a>**Wi-Fi hotspot / access point** | A device providing a local Wi-Fi network. Internet access is not implied. | The Pi hosts `IFI7386-G1` or `IFI7386-G2` for the Arduino. |
| <a id="ssid"></a>**SSID** | The broadcast name of a Wi-Fi network. | Select `TLU` for Pi internet access; restore the group SSID for testing. |
| <a id="ip-address"></a>**IP address** | An address identifying a network interface within the relevant network. | The Pi hotspot uses `10.42.0.1`; Arduino receives a different address. |
| <a id="network-port"></a>**Network port** | A number identifying a network service at an IP address; it is different from the Arduino’s USB/serial port. | The separate group servers normally listen on port 3000. |
| <a id="polling"></a>**Polling** | Repeatedly request current information rather than waiting for the server to send it unprompted. | The browser requests `/api/state` about once a second. |
| <a id="snapshot"></a>**Snapshot** | A message describing the current state of the reported items, rather than only a change event. | Group 1 sends current chair readings every two seconds. |
| <a id="heartbeat"></a>**Heartbeat** | A repeated message used as evidence that a device is communicating. It does not prove every connected sensor works. | Group 2’s heartbeat does not prove the RC522 can read a card. |
| <a id="stale-data-and-expiry"></a>**Stale data and expiry** | Data is stale when it is too old to trust as current. Expiry rules remove or change how old information is presented. | Old chair readings become unknown, not free; old ticket guidance disappears. |

## Git and shared code

| Term | Meaning | Course example |
|---|---|---|
| <a id="git"></a>**Git** | A version-control tool that records changes as commits and supports sharing them between repositories. | The development computer and Pi each have their own Git copy. |
| <a id="github"></a>**GitHub** | The online service used to host and share the group’s Git repository. Git and GitHub are different things. | The group shares both host code and Arduino source in one GitHub repository. |
| <a id="repository"></a>**Repository** | The project’s version-controlled files and history. A local repository and its remote copy are separate. | The group repository contains `host/` and both sketch folders. |
| <a id="clone"></a>**Clone** | Create a local Git copy of a repository, including its history and remote connection. | Clone once on the development computer and once on the Pi. |
| <a id="commit"></a>**Commit** | A recorded local version of selected changes, identified by a commit ID. It is not automatically published. | Record the code commit tested on the Pi. |
| <a id="push"></a>**Push** | Send local commits to a remote repository. It does not install firmware or update another machine automatically. | Push the reviewed change to the group repository on GitHub. |
| <a id="pull"></a>**Pull** | Retrieve remote commits and incorporate them into the current local branch. It does not restart a server. | On the Pi, pull while connected to TLU, then restore the hotspot and restart. |
| <a id="remote--origin"></a>**Remote / origin** | A named connection to another Git repository. A clone normally names its source remote `origin`. | Check that `origin` points to the group repository rather than the course repository. |
| <a id="branch--main"></a>**Branch / main** | A named line of development. `main` is the branch shared in the course’s simple one-writer workflow. | Coordinate before another member edits and pushes to `main`. |
| <a id="diff"></a>**Diff** | A comparison showing what changed between versions or between saved work and a commit. | Inspect the agent’s added and removed lines before keeping a change. |
| <a id="staging"></a>**Staging** | Select the file changes to include in the next commit. | A host-only file selection does not include a modified `.ino` file. |
| <a id="collaborator"></a>**Collaborator** | A person granted access to work on a shared repository. | Invite teammates to the group repository and accept the invitations. |

## AI-assisted development and testing

| Term | Meaning | Course example |
|---|---|---|
| <a id="ai-agent"></a>**AI agent** | An AI tool that can inspect project files and use permitted tools to implement a task. Its result still needs human review and testing. | Use Antigravity’s desktop app on the development clone. |
| <a id="prompt"></a>**Prompt** | The instruction and context given to the agent, including the problem, scope and expected result. | Specify the observed issue and acceptance checks before requesting changes. |
| <a id="scope"></a>**Scope** | The agreed boundary of a change: what it should affect and what must stay working. | An interface task can leave the existing firmware and request fields unchanged. |
| <a id="code-review"></a>**Code review** | Inspect a proposed change and decide whether it matches the task and preserves required behaviour. | Check the diff, ask questions and request a correction before committing. |
| <a id="acceptance-criteria"></a>**Acceptance criteria** | Observable conditions used to decide whether the requested change works. | After chair readings expire, the summary must show unknown rather than free. |
| <a id="regression-test"></a>**Regression test** | Check that behaviour which previously worked still works after a change. | Retest both chairs independently after adding a summary. |
| <a id="integration-test"></a>**Integration test** | Check that connected components work together. State which components are actually included. | A host API test is useful but does not replace the physical Arduino-to-browser test. |
| <a id="simulation"></a>**Simulation** | Represent an input or system behaviour without using the actual component. Label what is simulated. | A host simulator helps isolate faults but does not prove an FSR or RFID reader works. |
| <a id="recovery"></a>**Recovery** | Return to an understood working state after a failure. | Reconnect the board and check that fresh readings reach the correct display. |
| <a id="deployment--device-update"></a>**Deployment / device update** | Put a selected code version into use on the intended device. Different targets require different steps. | Pi: pull and restart the server. Arduino: USB Upload from the development computer. |

## Safety and scope

| Term | Meaning | Course example |
|---|---|---|
| <a id="feasible"></a>**Feasible** | Realistic to complete with the available time, skills, materials, and access. | Choose one complete sensor-to-feedback path using the available kit. |
| <a id="safety-critical"></a>**Safety-critical** | A system is safety-critical when failure could cause serious harm. Session 1 projects must not depend on the prototype for health or safety. | A classroom comfort cue must not claim to provide a medical warning or guarantee safe air. |
| <a id="ethics"></a>**Ethics** | Principles used to consider whether the project treats people fairly and avoids unnecessary harm, pressure, surveillance, or use of personal data. | Obtain consent and avoid collecting unnecessary identifying information. |

For complete procedures, use the linked session pages and the [readings and technical references](academic-readings.md). Course-specific message fields, timeouts and hardware settings are defined in the session instructions.

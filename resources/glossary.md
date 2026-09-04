# Course glossary

[Course home](../README.md) · [Session 1](../sessions/01-user-needs-and-initial-project-concept/README.md) · [Academic readings](academic-readings.md)

This glossary explains important course terms in simple English. The examples show how the terms connect to the shared study-room comfort-cue example used in Session 1.

## People, goals, and context

### User

A person who directly or indirectly interacts with a system.

**Example:** A student who sees a room-status cue and decides whether to open a window.

### Primary user

The main user in the scenario your team is designing. A project can affect several people, but the first concept should name one clear primary user.

**Example:** A student taking part in a long group-work session.

### User goal

What the user wants or needs to achieve. A goal is not the same as a system feature.

**Example:** Continue focused group work in a comfortable room. “Use a CO₂ sensor” is not a user goal.

### Context of use

The conditions around an interaction. Context includes the user, goal, task, place, social situation, organisation, available technology, and other constraints.

**Example:** A bookable study room, a group working together, limited ventilation, shared responsibility, and people who do not all face the same direction.

### Constraint

A condition that limits the design or affects whether it works.

**Example:** The cue must be visible but should not interrupt a discussion.

### Stakeholder

A person or group affected by the project or able to affect it. A stakeholder is not always the primary user.

**Example:** Students are primary users of the room cue. University facilities staff may also be stakeholders.

### Workaround

What a person currently does to manage a problem when there is no good direct solution.

**Example:** A student opens a window based only on personal judgement because the group has no shared way to discuss room comfort.

### Psychological safety

A shared feeling that team members can ask questions, challenge ideas, make mistakes, and admit uncertainty without being embarrassed or punished.

## Claims and evidence

### Hypothesis

An idea or claim that may be true but has not yet been confirmed. A hypothesis should be checked with evidence.

**Example:** Students may notice poor room comfort too late.

### Evidence

Information that helps you judge a claim. Evidence may come from a trustworthy source, observation, conversation, test, or measurement.

**Example:** Two students describe when they notice discomfort and what their groups usually do.

### Assumption

Something the team currently treats as true without enough evidence.

**Example:** The team assumes that everyone will understand a blue light as “comfortable.”

### Interpretation

What the team thinks an observation or statement may mean. An interpretation is not the same as the original evidence.

**Example:** A participant says nobody wants to interrupt the group. The team interprets this as a possible problem of shared responsibility.

### Anonymised evidence

Evidence from which identifying details have been removed. Another reader should not be able to identify the participant from the notes.

**Example:** Write “Participant 1, student using a group room,” not the person's name or contact details.

## Interaction

### Interactive system

A system that receives input, changes or responds, and gives output that affects what a person understands or does next. It does not need to have a screen.

**Example:** A bus stop-request system receives a button press, changes state, and gives sound and visual feedback.

### Input

An action, signal, or change in the environment that enters the system.

**Example:** A button press or a value from a sensor.

### System state

What the system currently knows, stores, or treats as true.

**Example:** The room status is “Comfortable” or “Action suggested.”

### Output

What the system produces or changes in the physical or digital world.

**Example:** A light changes and a web page shows a new message.

### Feedback

Output that helps the user understand what happened, what the system is doing, or what to do next.

**Example:** The label “Open window or take a short break” explains the meaning of the changed status.

### Interface

Everything through which the user and system communicate. An interface can include controls, screens, sound, light, movement, sensors, and physical objects.

**Example:** A labelled physical indicator and a simple web-status page.

### Interaction loop

The connected sequence from a user's goal and action to system input, state change, output, feedback, and the user's next action.

### System boundary

The line between what the system does and what happens outside it. Defining the boundary helps the team decide what the first version must include.

**Example:** The system receives a sensor value and changes a status. Opening the window is an action outside the system.

### Threshold

A value or condition that causes a system to change state.

**Example:** The status changes when a simulated sensor value goes above an initial threshold.

## Design concepts

### Human-centred design

An approach that keeps people, their goals, tasks, abilities, and contexts central throughout design and development. Teams involve users, use evidence, evaluate ideas, and improve them through repeated cycles.

### Value proposition

A short claim about how a concept may help a specific user in a specific context. It describes a human benefit, not a list of product features.

**Example:** A calm cue may help a student group decide when to ventilate without repeatedly checking raw data.

### Use scenario

A short and concrete story showing how one interaction happens from trigger to outcome.

**Example:** The room status changes, a student notices the cue, the group opens a window, and the status later returns to comfortable.

### Prototype

A representation made to explore or test a design question. A prototype is not the finished product.

**Example:** Movable state cards can test whether people understand three different room-status messages.

### Low-fidelity prototype

A deliberately simple prototype that is quick and cheap to change. “Fidelity” means how closely the prototype looks or behaves like the planned final system.

**Example:** Paper screens, cardboard, sticky notes, or a person changing state cards.

### Prototype question

The specific question a prototype should help answer.

**Example:** Can a first-time user understand the state change without spoken help?

### Wizard-of-Oz prototype

A prototype in which a person secretly or openly performs a system action that is not yet automated.

**Example:** A team member changes the room-status card when a simulated sensor value crosses a threshold.

### Iteration

A repeated cycle of learning, changing the design, and testing again.

### Peer feedback

Focused comments from students of similar status. Good peer feedback explains what was understood, what was unclear, which assumption may be risky, and what question should be investigated next.

### Criterion and criteria

A **criterion** is one question or standard used to judge an idea. **Criteria** is the plural form.

**Example:** User access, safety, and feasibility are three criteria for comparing project ideas.

## Safety and scope

### Feasible

Realistic to complete with the available time, skills, materials, and access.

### Safety-critical

A system is safety-critical when failure could cause serious harm. Session 1 projects must not depend on the prototype for health or safety.

**Example:** A classroom comfort cue must not claim to provide a medical warning or guarantee safe air.

### Ethics

Principles used to consider whether the project treats people fairly and avoids unnecessary harm, pressure, surveillance, or use of personal data.

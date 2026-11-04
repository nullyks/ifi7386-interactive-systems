# Readings and technical references

[Course home](../README.md) · [All sessions](../sessions/README.md) · [Glossary](glossary.md)

Shared references for **Sessions 1–5**. Sessions 1–2 emphasise research and design literature; Sessions 3–5 also need practical hardware, networking, version-control and AI-tool documentation. Full-text readings are identified separately from publication records and standards overviews. The full ISO standards are not required reading.

Session coverage and the technical references were reviewed on **2 November 2026**; the Session 5 account, authentication and Git-installation guidance was updated on **4 November 2026**. Use the linked session instructions for the classroom wiring, tested library versions, message fields and workflow. General documentation explains the underlying tools; it does not replace the group-specific instructions.

## Find references for your session

| Session | Focus | References |
|---|---|---|
| [1 — User needs and initial concept](../sessions/01-user-needs-and-initial-project-concept/README.md) | Users, context, evidence, value, teamwork and early prototypes | [Session 1 reading list](#start-here) |
| [2 — Interaction, architecture and prototyping](../sessions/02-interaction-architecture-and-prototyping/README.md) | Architecture, states, accessibility, ergonomics and prototype methods | [Session 2 reading list](#session-2-readings) |
| [3 — Wizard-of-Oz and Arduino](../sessions/03-wizard-of-oz-and-arduino-prototyping/README.md) | Participant study, input/output, sketches and a feasible Hi-Fi slice | [Session 3 references](#session-3--wizard-of-oz-and-arduino) |
| [4 — Integration and collaboration](../sessions/04-integration-and-collaborative-development/README.md) | Sensors, Pi networking, HTTP/JSON, state and recovery | [Session 4 references](#session-4--integration-and-collaborative-development) |
| [5 — AI-assisted development and Git](../sessions/05-ai-assisted-development-and-git-workflow/README.md) | Agent prompts, review, shared code, device updates and testing | [Session 5 references](#session-5--ai-assisted-development-and-git) |

## Start here

The following sources are the most useful preparation and review for Session 1.

### Interaction design, human-centred design, and context

1. **The Open University. _An introduction to interaction design_.** A free university course covering interaction design, user-centred design, the design context, research methods, sketching, and prototyping. Read the relevant HTML sections directly; registration is not needed to view them.
   - [Course introduction](https://www.open.edu/openlearn/mod/oucontent/view.php?id=66703&intro=1&section=0)
   - [What is interaction design?](https://www.open.edu/openlearn/mod/oucontent/view.php?id=66703&section=1)
   - Use the page contents to continue to **Goals and principles of user-centred design**, **The who, where and what of the design context**, and **Interaction design activities and methods**.

2. **Maguire, M. (2001). _Context of use within usability activities_.** _International Journal of Human-Computer Studies, 55_(4), 453–483. Public repository record with a downloadable full text, licensed CC BY-NC-ND 4.0.
   - [Open repository copy](https://repository.lboro.ac.uk/articles/journal_contribution/Context_of_use_within_usability_activities/9349751)
   - DOI: [10.1006/ijhc.2001.0486](https://doi.org/10.1006/ijhc.2001.0486)

### Prototypes and scenarios

3. **Houde, S., & Hill, C. (1997). _What do prototypes prototype?_** In _Handbook of Human-Computer Interaction_ (2nd ed.). Public, university-hosted full text.
   - [Open PDF](https://hci.stanford.edu/courses/cs247/2012/readings/WhatDoPrototypesPrototype.pdf)

4. **Lim, Y.-K., Stolterman, E., & Tenenberg, J. (2008). _The anatomy of prototypes: Prototypes as filters, prototypes as manifestations of design ideas_.** _ACM Transactions on Computer-Human Interaction, 15_(2), Article 7. Public, author-hosted full text.
   - [Open PDF](https://faculty.washington.edu/jtenenbg/publications/limAnatomyOfPrototypes-tochi2008.pdf)
   - DOI: [10.1145/1375761.1375762](https://doi.org/10.1145/1375761.1375762)

5. **Carroll, J. M. (2000). _Five reasons for scenario-based design_.** _Interacting with Computers, 13_(1), 43–60. The public university record contains the abstract, complete citation, and DOI.
   - [Penn State research record](https://pure.psu.edu/en/publications/five-reasons-for-scenario-based-design-2/)
   - DOI: [10.1016/S0953-5438(00)00023-0](https://doi.org/10.1016/S0953-5438(00)00023-0)

### Teams, projects, and peer feedback

6. **Oakley, B., Felder, R. M., Brent, R., & Elhajj, I. (2004). _Turning student groups into effective teams_.** _Journal of Student Centered Learning, 2_(1), 9–34. Public, university-hosted full text.
   - [Open PDF](https://engr.ncsu.edu/wp-content/uploads/drive/1ofGhdOciEwloA2zofffqkr7jG3SeKRq3/2004-Oakley-paper%28JSCL%29.pdf)

7. **Blumenfeld, P. C., Soloway, E., Marx, R. W., Krajcik, J. S., Guzdial, M., & Palincsar, A. (1991). _Motivating project-based learning: Sustaining the doing, supporting the learning_.** _Educational Psychologist, 26_(3–4), 369–398. Public, university-hosted full text.
   - [Open PDF](https://web.eecs.umich.edu/~mjguz/csl/home.cc.gatech.edu/allison/uploads/4/blumenfeld1991.pdf)
   - DOI: [10.1080/00461520.1991.9653139](https://doi.org/10.1080/00461520.1991.9653139)

8. **Topping, K. (1998). _Peer assessment between students in colleges and universities_.** _Review of Educational Research, 68_(3), 249–276. Public, university-hosted full text.
   - [Open PDF](https://moodle-ut.univ-toulouse.fr/pluginfile.php/97836/mod_folder/content/0/Topping%20-%201998%20-%20Peer%20Assessment%20between%20Students%20in%20Colleges%20and%20U.pdf)
   - DOI: [10.3102/00346543068003249](https://doi.org/10.3102/00346543068003249)

## Official standards and public source records

These public pages verify the concepts and bibliographic details. The full ISO standards are not required reading for Session 1.

- **ISO 9241-210:2019**, _Human-centred design for interactive systems_: [official ISO overview](https://www.iso.org/standard/77520.html).
- **ISO 9241-11:2018**, _Usability: Definitions and concepts_: [official ISO overview](https://www.iso.org/standard/63500.html).
- **Cockton, G. (2006)**, _Designing worth is worth designing_: [public Northumbria University research record](https://researchportal.northumbria.ac.uk/en/publications/designing-worth-is-worth-designing/).
- **Edmondson, A. (1999)**, _Psychological safety and learning behavior in work teams_: [public publisher page and abstract](https://journals.sagepub.com/doi/10.2307/2666999).

## How the readings connect to Session 1

| Topic | Best starting point |
|---|---|
| Interactive systems and feedback | Open University, Sections 1 and 2 |
| Human-centred design | Open University, Section 2; ISO 9241-210 overview |
| User and context | Open University, Section 3; Maguire |
| Value proposition | Cockton public research record |
| Main use scenario | Carroll public research record |
| Low-fidelity prototype | Houde and Hill; Lim, Stolterman, and Tenenberg |
| Team formation | Oakley and colleagues |
| Project work | Blumenfeld and colleagues |
| Peer feedback | Topping |

## Session 2 readings

The following sources support architecture, interaction flow, ergonomics, accessibility, and the choice of prototype fidelity and method. Every reading link is either open full text or a clearly labelled public standards overview. You do not need to buy a standard or use a university-library login for this session.

### Architecture, data flow, and state

9. **ISO/IEC/IEEE 42010:2022. _Software, systems and enterprise - Architecture description_.** The official overview explains the role and structure of an architecture description. The full standard is not required reading.
   - [Official ISO overview](https://www.iso.org/standard/74393.html)

10. **Fielding, R. T. (2000). _Software architecture_.** Chapter 1 of _Architectural Styles and the Design of Network-based Software Architectures_. The open HTML chapter defines components, connectors, data, configurations, and architectural views.
    - [Open dissertation chapter](https://ics.uci.edu/~fielding/pubs/dissertation/software_arch.htm)

11. **Harel, D. (1987). _Statecharts: A visual formalism for complex systems_.** _Science of Computer Programming, 8_(3), 231-274. A classic peer-reviewed account of state-based behavioural modelling.
    - [University-hosted open PDF](https://www.csd.uoc.gr/~hy565/docs/pdfs/papers/statecharts_visual_formalism.pdf)
    - DOI: [10.1016/0167-6423(87)90035-9](https://doi.org/10.1016/0167-6423(87)90035-9)

12. **MIT 6.813/6.831. _Reading 12: Input_.** An open course reading with concrete interface examples of events, state machines, cancellation, and feedback.
    - [Open HTML reading](https://web.mit.edu/6.813/www/sp17/classes/12-input/)

### Interaction patterns, ergonomics, and accessibility

13. **van Welie, M., & Trætteberg, H. (2000). _Interaction patterns in user interfaces_.** The paper presents interaction patterns from an end-user and usability perspective.
    - [Open author-hosted PDF](https://www.welie.com/papers/PLoP2k-Welie.pdf)

14. **ISO 9241-110:2020. _Ergonomics of human-system interaction - Part 110: Interaction principles_.** Use the official overview for the scope of technology-independent interaction principles. The full standard is not required reading.
    - [Official ISO overview](https://www.iso.org/standard/75258.html)

15. **ISO 9241-171:2025. _Ergonomics of human-system interaction - Part 171: Software accessibility_.** The official overview explains its scope across physical, sensory, and cognitive abilities and contexts of use. The full standard is not required reading.
    - [Official ISO overview](https://www.iso.org/standard/86308.html)

16. **W3C. (2024). _Web Content Accessibility Guidelines WCAG 2.2_.** The complete W3C Recommendation and its filtering tool are public primary sources for web-accessibility principles and success criteria.
    - [WCAG 2.2 Recommendation](https://www.w3.org/TR/WCAG22/)
    - [WCAG 2.2 Quick Reference](https://www.w3.org/WAI/WCAG22/quickref/)

### Prototype fidelity and Wizard-of-Oz

17. **Virzi, R. A., Sokolov, J. L., & Karis, D. (1996). _Usability problem identification using both low- and high-fidelity prototypes_.** In _Proceedings of CHI 96_, 236-243. Peer-reviewed comparison of problems found with low- and high-fidelity prototypes. ACM marks this article as free access.
    - [Free ACM full text](https://doi.org/10.1145/238386.238516)

18. **Walker, M., Takayama, L., & Landay, J. A. (2002). _High-fidelity or low-fidelity, paper or computer? Choosing attributes when testing web prototypes_.** _Proceedings of the Human Factors and Ergonomics Society Annual Meeting, 46_(5), 661-665.
    - [Author-hosted preprint](https://www.leilatakayama.org/downloads/Takayama.Prototypes_HFES2002_prepress.pdf)
    - DOI: [10.1177/154193120204600513](https://doi.org/10.1177/154193120204600513)

19. **Porcheron, M., Fischer, J. E., & Reeves, S. (2020). _Pulling back the curtain on the Wizards of Oz_.** _Proceedings of the ACM on Human-Computer Interaction, 4_(CSCW3), Article 243. Peer-reviewed analysis of how the wizard, interface, researchers, and participants jointly shape a Wizard-of-Oz study.
    - [Open author-hosted PDF](https://people.cs.nott.ac.uk/pszsr/files/porcheron-2020-wizard-of-oz.pdf)
    - DOI: [10.1145/3432942](https://doi.org/10.1145/3432942)

## How the readings connect to Session 2

| Topic | Best starting point |
|---|---|
| Architecture and system boundaries | Fielding; ISO/IEC/IEEE 42010 overview |
| States, events, and transitions | MIT open reading; Harel |
| Interaction patterns | van Welie and Trætteberg; ISO 9241-110 |
| Ergonomics | ISO 9241-110; ISO 9241-171 |
| Web accessibility | WCAG 2.2; ISO 9241-171 |
| Low- and high-fidelity comparison | Houde and Hill; Lim and colleagues; Virzi and colleagues; Walker and colleagues |
| Wizard-of-Oz | Porcheron, Fischer, and Reeves |

## Session 3 — Wizard-of-Oz and Arduino

Start with the [Wizard-of-Oz study](../sessions/03-wizard-of-oz-and-arduino-prototyping/activities/01-wizard-of-oz-study.md), then follow the Arduino activities in order. Reuse the [prototype and Wizard-of-Oz literature](#prototype-fidelity-and-wizard-of-oz) above: realistic technical behaviour should answer a design question informed by the study.

| Topic | Source | What to focus on |
|---|---|---|
| Participant tasks, operator rules and evidence | [Course study activity](../sessions/03-wizard-of-oz-and-arduino-prototyping/activities/01-wizard-of-oz-study.md); Porcheron, Fischer and Reeves, reading 19 | Keep the participant goal, operator script and observation separate. Obtain consent and explain simulated behaviour in the debrief. |
| Board setup, pins, sketch and first upload | [Course Arduino introduction](https://github.com/nullyks/Arduino-sissejuhatus); [Arduino upload guide](https://support.arduino.cc/hc/en-us/articles/4733418441116-Upload-a-sketch-in-Arduino-IDE) | Board and USB-port selection, compilation, upload and Serial Monitor. Use the actual board model. |
| Button input and LED output | [Course button-to-LED activity](../sessions/03-wizard-of-oz-and-arduino-prototyping/activities/04-button-to-led-loop.md); [Arduino InputPullupSerial example](https://docs.arduino.cc/built-in-examples/digital/InputPullupSerial/) | With the course pull-up circuit, pressed is LOW. Follow the course's pins and 470 Ω LED resistor; inspect bounce before counting presses. |
| Analog sensing | [Course sensor examples](https://github.com/nullyks/Arduino-erinevad-andurid); [Arduino analogRead reference](https://docs.arduino.cc/language-reference/en/functions/analog-io/analogRead/) | Connect a physical quantity to a reading, then consider calibration, placement and noise. A reading is not automatically evidence of a person's intent. |
| Physical visual feedback and movement | [Screens and LED elements](https://github.com/nullyks/Arduino-ekraanid-ja-led-elemendid); [motors and power](https://github.com/nullyks/Arduino-mootorid-ja-toide) | Compare feedback types, drivers and power requirements for the available kit. Check each example's board compatibility rather than assuming all UNO versions are interchangeable. |
| Optional browser-interface route | [UNO R4 WiFi web-server material](https://github.com/nullyks/Arduino_UNO_R4_server) | This route uses UNO R4 WiFi, aWOT and a browser. Here the Arduino hosts the network and web server. It is an option to inspect, not a requirement to build every component station. |
| Selecting a Hi-Fi slice | [Course build decision](../sessions/03-wizard-of-oz-and-arduino-prototyping/activities/06-hifi-slice-and-handover.md); Houde and Hill and Lim et al., readings 3–4 | Choose the physical behaviour needed to answer one question. Record what will remain simulated and the first bench-test success condition. |

## Session 4 — Integration and Collaborative Development

The architecture here differs from Session 3's optional Arduino web-server route: **the Pi hosts the group hotspot and Node.js server; Arduino is an HTTP client; the browser polls the Pi**. These are the two independent applications developed further in Session 5.

| Topic | Source | What to focus on |
|---|---|---|
| UNO R4 WiFi and network client | [Arduino board documentation](https://docs.arduino.cc/hardware/uno-r4-wifi/); [WiFiS3 examples](https://docs.arduino.cc/tutorials/uno-r4-wifi/wifi-examples/); [course Wi-Fi diagnosis](../sessions/04-integration-and-collaborative-development/wifi-troubleshooting.md) | Distinguish joining Wi-Fi, receiving an IP address and reaching the server. The course uses an OPEN group hotspot. |
| Pi hotspot and network settings | [Raspberry Pi networking documentation](https://www.raspberrypi.com/documentation/computers/configuration.html#wireless-connection); [course Pi setup](../sessions/04-integration-and-collaborative-development/setup.md) | The course defines the SSID, `ifi-lab` profile and fixed hotspot address. Do not replace these with unrelated default hotspot settings. |
| HTTP requests, JSON and validation | [HTTP methods](https://developer.mozilla.org/en-US/docs/Web/HTTP/Reference/Methods); [working with JSON](https://developer.mozilla.org/en-US/docs/Learn_web_development/Core/Scripting/JSON); [course data contract](../sessions/04-integration-and-collaborative-development/data-contract.md) | Match method, endpoint, fields, types and IDs. HTTP 200 confirms acceptance, not correct user-visible feedback. |
| Server and browser responsibilities | [Node.js HTTP API](https://nodejs.org/api/http.html); [course code guide](../sessions/04-integration-and-collaborative-development/code-guide.md) | Node receives requests and holds state; browser JavaScript requests state and updates HTML/SVG. The host examples use built-in modules. |
| Pressure sensing and occupancy | [Group 1 guide](../sessions/04-integration-and-collaborative-development/group-1-library.md); [Group 1 application](../sessions/04-integration-and-collaborative-development/examples/group-1-library/README.md) | Use real mounted-chair measurements, independent thresholds, smoothing and hysteresis. Pressure does not prove a seated person; unmeasured chairs have no known availability. |
| RFID reading and ticket mapping | [AMRFID library](https://github.com/guicaiala/AMRFID); [Group 2 guide](../sessions/04-integration-and-collaborative-development/group-2-ticket.md); [Group 2 application](../sessions/04-integration-and-collaborative-development/examples/group-2-ticket/README.md) | Read actual UIDs and map them on the host. Follow the tested library versions in setup. Initialisation and heartbeats do not prove the reader can read a card; UID matching is not secure authentication. |
| Freshness, failure and recovery | [Data contract](../sessions/04-integration-and-collaborative-development/data-contract.md); [acceptance tests](../sessions/04-integration-and-collaborative-development/testing.md); [verification record](../sessions/04-integration-and-collaborative-development/verification.md) | Compare chair snapshots, ticket events, reader heartbeats, expiry and host loss. Distinguish simulated checks, compile checks and physical hardware evidence. |

The Session 2 readings still apply: check whether updated states and error messages are understandable, perceivable and accessible. A successful network request is only one part of the complete interaction.

## Session 5 — AI-Assisted Development and Git

Start with the [group repository and two-clone activity](../sessions/05-ai-assisted-development-and-git-workflow/activities/01-team-repository-and-two-clones.md). Use the **graphical Antigravity desktop app on the development computer**, and use the Pi's desktop Wi-Fi menu to switch between **TLU for GitHub access** and the **group hotspot for physical testing**. Ethernet internet is not assumed.

| Topic | Source | What to focus on |
|---|---|---|
| GitHub account, development sign-in and Git installation | [Create an account](https://docs.github.com/en/account-and-profile/how-tos/account-management/creating-an-account-on-github); [Git for Windows](https://gitforwindows.org/); [HTTPS credentials](https://docs.github.com/en/get-started/git-basics/caching-your-github-credentials-in-git); [Git on Linux/Pi OS](https://git-scm.com/install/linux); [course setup steps](../sessions/05-ai-assisted-development-and-git-workflow/activities/01-team-repository-and-two-clones.md) | The Windows route uses bundled Git Credential Manager and browser sign-in. Author name/email labels commits; it is not authentication. Public Pi clones need Git and internet access, but no GitHub login. |
| A group repository and separate local copies | [Create a GitHub repository](https://docs.github.com/en/repositories/creating-and-managing-repositories/creating-a-new-repository); [clone a repository](https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository); [course setup activity](../sessions/05-ai-assisted-development-and-git-workflow/activities/01-team-repository-and-two-clones.md) | Keep the host and Arduino source together. Clone once on the development computer and once on the Pi. Invite collaborators and check the remote URL. |
| Sharing and retrieving versions | [Push commits](https://docs.github.com/en/get-started/using-git/pushing-commits-to-a-remote-repository); [get remote changes](https://docs.github.com/en/get-started/using-git/getting-changes-from-a-remote-repository) | Save, commit, push and pull are separate operations. Use the course's one-writer `main` workflow and compare the delivered commit IDs. |
| Agent access to existing code | [Antigravity getting started](https://antigravity.google/docs/getting-started); [projects and Local mode](https://antigravity.google/docs/projects/); [course agent activity](../sessions/05-ai-assisted-development-and-git-workflow/activities/03-develop-with-antigravity.md) | Open the existing development clone and use Local mode. Give the agent the observed issue, relevant files, scope and observable success conditions. |
| Reviewing and committing an agent's changes | [Antigravity Review pane](https://antigravity.google/docs/review-changes/) | Read file differences, send specific feedback, select the intended files and commit/push after checking the result. Agent output is a proposal to verify. |
| Acceptance and regression checks | [Course change cards](../sessions/05-ai-assisted-development-and-git-workflow/activities/02-find-and-specify-improvements.md); [test log and handover](../sessions/05-ai-assisted-development-and-git-workflow/activities/05-demonstrate-and-handover.md); [Node.js test runner](https://nodejs.org/api/test.html) | State the expected change and the original behaviour that must still work. The supplied host check runs with `node --test host/test.js`; it does not test wiring or upload firmware. |
| Updating the Pi server and interface | [Course publish/update/test sequence](../sessions/05-ai-assisted-development-and-git-workflow/activities/04-publish-update-and-test.md) | Push from development; stop the Pi server; use its GUI to join TLU and pull; restore the existing group hotspot; start the updated server and test. |
| Updating Arduino firmware | [Course firmware example](../sessions/05-ai-assisted-development-and-git-workflow/activities/04-publish-update-and-test.md#optional-example-update-arduino-firmware); [Arduino upload guide](https://support.arduino.cc/hc/en-us/articles/4733418441116-Upload-a-sketch-in-Arduino-IDE) | Commit and push the `.ino` source to the same repository, then USB Upload from the development computer using Arduino IDE. Pulling on the Pi does not program the board. Record the firmware version separately when needed. |

The two required rounds improve the interface and server; the firmware example is optional. Continue to use the earlier sessions' user goal, evidence, architecture and accessibility checks when choosing improvements. A clean diff or a published commit alone does not establish that the user's interaction works.

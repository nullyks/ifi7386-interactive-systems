# Session 5 — AI-Assisted Development and the Git Workflow

[Course home](../../README.md) · [All sessions](../README.md) · [Glossary](../../resources/glossary.md) · [Readings and references](../../resources/academic-readings.md)

**Duration:** 135 minutes in three 45-minute blocks · **Format:** team development with an AI agent · **Working language:** English

## Where we are going

Develop your existing group project with an AI agent, then deliver and test the change on your Raspberry Pi 400. Use your own group GitHub repository and two local Git copies: one on a development computer and one on the Pi. The examples use **Google Antigravity's graphical desktop app** on the development computer. Another AI development tool is acceptable if you can show the same workflow.

Complete the loop twice: first for a small interface improvement, then for a small server improvement. Your group chooses what needs improving and writes the success conditions. The agent helps implement the change; your group reviews and tests it.

## By the end you can

- create a group repository containing your existing server, interface and Arduino sketches;
- distinguish the development copy, GitHub repository and Pi test copy;
- turn an observed problem into a bounded agent prompt and an observable test;
- inspect an agent's changes and check the result locally;
- commit and push a reviewed change, pull it on the Pi, restart and test it;
- explain how Arduino firmware source is shared through GitHub and uploaded to the board over USB from the development computer;
- switch the Pi between **TLU for GitHub access** and **your group hotspot for Arduino testing**, using the desktop Wi-Fi controls;
- identify the tested version and explain what remains unverified.

## Before starting

Follow [Activity 01](activities/01-team-repository-and-two-clones.md) from the beginning. It now includes **creating a free GitHub account, installing Git, setting the commit author and signing Git into GitHub**, followed by both clones. Prepare the account and software before class where possible.

The recommended Windows route uses **Git for Windows + its included Git Credential Manager + HTTPS browser sign-in**. For the Pi, use a public group repository so download-only access needs no GitHub login. The [Pi instructions](activities/01-team-repository-and-two-clones.md#4-clone-on-the-pi-400) include `git --version` and installation if Git is missing. An alternative for a Mac/Linux development laptop is included in the same activity.

## Session route

| Focus | Open in class | Team result |
|---|---|---|
| Recall the working prototype and demonstrate delivery | [Delivery loop](#how-your-change-reaches-the-pi) | Name the three code locations and record the starting behaviour. |
| Set up the group repository and two clones | [Activity 01](activities/01-team-repository-and-two-clones.md) | C1: own repository, development Git sign-in, Git on Pi and a working baseline. |
| Find and specify improvements | [Activity 02](activities/02-find-and-specify-improvements.md) | One interface issue and one server issue with success conditions. |
| Develop round 1: interface | [Activity 03](activities/03-develop-with-antigravity.md) | Review the change and test it on the development computer. |
| Publish, update and test round 1 | [Activity 04](activities/04-publish-update-and-test.md) | C2: update the Pi and test with physical input. |
| Record the result, explain the code and rotate roles | [Team roles](#how-to-work-together) | Keep the next change small; take a short break if needed. |
| Develop round 2: server | [Activity 03](activities/03-develop-with-antigravity.md) | A different member drives; review and test the server change. |
| Publish, update and test round 2 | [Activity 04](activities/04-publish-update-and-test.md) | C3: repeat delivery and record the tested commit. |
| Demonstrate and hand over | [Activity 05](activities/05-demonstrate-and-handover.md) | Show both changes, evidence and one remaining issue. |

## Key terms for today

| Term | Simple meaning |
|---|---|
| **Clone** | Create a local Git copy once on each computer. |
| **Commit** | Record a local version of selected changes. |
| **Push** | Share commits with the group repository on GitHub. |
| **Pull** | Retrieve changes into a local copy; it does not restart the server. |
| **AI agent** | A tool that can inspect and edit files within the task you give it. |
| **Firmware upload** | Install the compiled sketch over USB from the development computer. |

See the [course glossary](../../resources/glossary.md) for more terms and examples.

## How your change reaches the Pi

Edit both server code and Arduino firmware on your classroom computer or laptop. Keep both in the same group GitHub repository. The two devices receive their updates in different ways:

```mermaid
flowchart LR
    DEV["Development computer<br/>Edit and test"]
    GITHUB["GitHub<br/>Server + firmware source"]
    PI["Raspberry Pi 400<br/>Run the server"]
    ARDUINO["Arduino<br/>Run the firmware"]
    DEV -->|push| GITHUB
    GITHUB -->|pull| PI
    DEV -->|"USB upload<br/>Arduino IDE"| ARDUINO
```

1. **Develop on your computer.** Use Antigravity to change the code. Review and test the result, then **commit** to save a local version.
2. **Share through GitHub.** **Push** uploads your commits to the group's repository, including any changed `.ino` firmware files. Other development computers can **pull** this source before continuing the work.
3. **Update the device you changed.** For server/interface changes, connect the Pi to **TLU**, **pull**, restore the group **hotspot** and restart the server. For firmware changes, use **Arduino IDE on the development computer** to upload the committed sketch to the Arduino over **USB**. Then test the physical interaction with the Pi server.

**First setup:** use **clone** once on each computer to create its local Git copy. After that, repeat the three steps above for each change.

**Firmware example:** add a version message such as `Library firmware v2` to the regular Serial output in `library/library.ino`, review and compile it, commit and push the source, then upload that same version from the development computer using Arduino IDE. Check the new message alongside the readings in Serial Monitor. Group 2 can print a version message when reading a tag in `ticket/ticket.ino`. See the [firmware update steps](activities/04-publish-update-and-test.md#optional-example-update-arduino-firmware).

The Arduino sends readings or ticket scans to the Pi over Wi-Fi during testing. That data connection does not install firmware. Pulling the repository on the Pi downloads the `.ino` source too, but the board keeps running its previous firmware until a USB upload succeeds.

The two required development rounds below focus on the interface and server. The firmware path is an optional example or instructor demonstration; it does not add a third required round.

## The Pi has two Wi-Fi modes

Work at the Pi's own keyboard and monitor. There is **no Ethernet internet connection** in this lesson.

| Pi Wi-Fi mode | Use it for | What to expect |
|---|---|---|
| Connected to the open network **TLU** | Clone or pull from GitHub | The group hotspot is off; Arduino cannot send to it. |
| Hosting **IFI7386-G1** or **IFI7386-G2** | Run and test the integrated prototype | Internet access is not expected; GitHub updates wait until you switch back to TLU. |

Change modes in the **desktop Wi-Fi menu**. Reactivate the existing group hotspot profile, `ifi-lab`, with the same OPEN security, SSID and `10.42.0.1` address from Session 4. Do not change Arduino's SSID to TLU. The development computer can remain on its internet connection; use the Pi browser for the hardware test. See the [update sequence](activities/04-publish-update-and-test.md).

## How to work together

Use a **driver**, a **reviewer** and a **Pi/test owner**; larger teams can add an observer and recorder. Rotate the driver after the first loop. The reviewer checks that the agent solved the chosen problem and preserved the existing interaction. The Pi owner records network mode, version and test result.

For this exercise, use one shared `main` branch and one active writer at a time. Other members may clone and read the repository. Before a new writer starts, finish the previous push and pull the latest version on the new writer's development computer. Branches and pull requests can be introduced later.

## Completion evidence

Save the repository URL, the two prompts, the before/after observations and one test record per loop. Each record names the commit, Pi network switches, expected result, actual result and whether real hardware or simulation was used. At least one interface improvement and one server improvement must reach and be tested on the Pi. A local-only change is unfinished delivery.

If you also change firmware, record the source commit uploaded to the Arduino and its USB upload/test result separately from the server version running on the Pi.

## Next steps

Keep the working prototype, repository, prompts and test evidence ready for the peer test and documentation work in Session 6. Follow the [handover checklist](activities/05-demonstrate-and-handover.md#completion-checklist).

---

[Previous session](../04-integration-and-collaborative-development/README.md) · [All sessions](../README.md) · [Next session](../06-peer-testing-documentation-and-defence/README.md) · [Back to session route](#session-route)

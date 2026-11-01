# Session 5 — Instructor Preparation and Sources

[Student session](README.md)

## Prepare before class

- Keep the 135-minute format. Check each group's Session 4 baseline and retain a working copy with measured thresholds or actual UID mapping.
- Development computers need Git, Node >=18, a browser, Google Antigravity's **graphical desktop app**, a working Google sign-in and AI access. For the optional firmware demonstration, also prepare Arduino IDE, the Session 4 board/libraries and a USB data cable on the development computer. Check access on classroom computers before the lesson.
- Each Pi needs Raspberry Pi OS with a desktop, monitor, keyboard/mouse, Git and Node >=18. Installation is preparation, not the main exercise. These examples require no npm dependencies.
- **No Ethernet internet is assumed or used.** Verify that the Pi can connect to the open **TLU** network through the desktop Wi-Fi menu and reach GitHub. Check any portal or network restrictions on the actual classroom connection.
- Practise the reverse GUI action on the installed Pi desktop: reactivate its saved `ifi-lab` hotspot, retaining the group's OPEN SSID and `10.42.0.1/24`. Identify the exact menu entry and saved-connection choice for students. If the desktop's hotspot dialog offers only a new connection, prepare a GUI route to the saved connection before class. Do not replace this with a requirement for Ethernet or terminal-based network switching.
- Check both hotspot → TLU → hotspot cycles with the real board. Use the Pi's local screen; switching Wi-Fi interrupts remote access. Confirm that automatic network selection does not take the Pi back to TLU during a hardware test.
- Repository owners need GitHub accounts and the ability to invite teammates. Verify development-machine push authentication. Public example-only repositories make Pi cloning straightforward; prepare private-repository access in advance if required. Git commit author name/email may need configuring on a fresh classroom computer; use the student's chosen identity and clear personal sign-ins when leaving a shared machine.

## Teaching emphasis

Demonstrate one tiny visible change before independent work. Point to each boundary: the file saved locally, the reviewed commit, the commit visible on GitHub, the commit pulled on the Pi, and the restarted process. Make the Wi-Fi change visible in the Pi GUI. While on TLU the prototype is temporarily disconnected; that is a planned update stage, not an Arduino fault.

Use the diagram to distinguish the firmware path: edit the `.ino` in the development clone, review/compile it, commit and push to the same repository, then upload that committed version over USB from the development computer using Arduino IDE. A version message alongside regular Serial readings or a successful UID is a small optional example. GitHub stores the source; pulling on the Pi does not flash the Arduino, and the Arduino's Wi-Fi sensor messages do not update firmware. Record server and firmware source versions separately when they differ. This example is optional; the 135-minute route still requires two interface/server rounds, not an additional firmware round.

Use one active writer and `main` for the first lesson. Keep the Pi clone for running and testing; edits belong on the development computer. Avoid spending this session on branching, CI or automatic deployment. The intended result is two complete, explained delivery loops, not a large feature list.

The 80–90 minute slot provides reflection, role rotation and limited recovery/break time. If a group falls behind, shrink the selected changes and drop optional work; preserve the push/pull, GUI network switch, restart and physical test. A simulated or local-only outcome remains explicitly incomplete integration.

## Known starting-code issues

- Group 2's test uses sample UIDs and expected seats. A group's real `tickets.json` can cause a baseline failure. Record this first; help isolate test data from the real mapping rather than replacing students' real UIDs to make the test pass.
- Both existing servers parse the request URL before their request error handler. A malformed address can terminate the process. This is a bounded optional server improvement; students still choose their own two change cards.
- The examples intentionally store state in memory. Restarting clears it. Reader initialisation/heartbeats do not prove the RC522 antenna is working; keep the Session 4 limitations in the explanation.

These notes describe the reviewed starting code. The Session 5 materials do not silently change the Session 4 applications or implement students' improvements for them.

## Sources and verification scope

Official documentation consulted on **1 November 2026**:

- [Google Antigravity — Get started](https://antigravity.google/docs/getting-started): desktop project creation and adding an existing folder.
- [Google Antigravity — Projects](https://antigravity.google/docs/projects/): Local mode versus a separate worktree.
- [Google Antigravity — Review changes](https://antigravity.google/docs/review-changes/): file differences, feedback, staging, commit and push in the app.
- [Google Antigravity — Features](https://antigravity.google/docs/features/): integrated terminal and opening a local page.
- [Arduino — Upload a sketch in Arduino IDE](https://support.arduino.cc/hc/en-us/articles/4733418441116-Upload-a-sketch-in-Arduino-IDE): select the connected board/port, verify and upload from the development computer.
- [GitHub — Create a repository](https://docs.github.com/en/repositories/creating-and-managing-repositories/creating-a-new-repository), [upload files](https://docs.github.com/en/repositories/working-with-files/managing-files/adding-a-file-to-a-repository) and [clone](https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository): the initial group-repository route.
- [GitHub — Push commits](https://docs.github.com/en/get-started/using-git/pushing-commits-to-a-remote-repository) and [get remote changes](https://docs.github.com/en/get-started/using-git/getting-changes-from-a-remote-repository): sharing and retrieving versions.
- [Raspberry Pi — Desktop wireless configuration](https://www.raspberrypi.com/documentation/computers/configuration.html#wireless-connection) and [Bookworm's network menu](https://www.raspberrypi.com/news/bookworm-the-new-version-of-raspberry-pi-os/): GUI network selection and hotspot controls. Actual saved-profile activation must be checked on the classroom image; menu labels can differ.

The TLU network name, lack of Ethernet and need to switch through the GUI are classroom requirements supplied by the instructor. Documentation review does not establish TLU availability, installed-app behaviour or a successful physical test. Local checks cover teaching links, the supplied examples and a temporary Git delivery rehearsal; actual Antigravity/Pi GUI and hardware checks remain pre-class preparation.

Authoring checks completed on 1 November 2026:

- 277 repository-local Markdown file links and heading anchors resolve; code fences are balanced.
- The session route covers minutes 0–135 without gaps or overlaps.
- Both supplied integration tests pass with their bundled mappings, using `node --test host/test.js` from a project root.
- For both groups, temporary local development/test clones were used to rehearse commit, push, fast-forward pull, matching commit IDs, root-level server startup, updated HTML delivery and simulated API input. This used local bare repositories, not live GitHub, and did not exercise Wi-Fi or physical hardware.

# Activity 04 — Publish, Update and Test

[Session 5](../README.md) · [Development activity](03-develop-with-antigravity.md) · [Final handover](05-demonstrate-and-handover.md)

**Time: about 15 minutes per round · Repeat after each reviewed change**

```text
Development: review → commit → push
Pi: stop → Wi-Fi to TLU → pull → Wi-Fi to group hotspot → start → test
```

## 1. Commit and push on the development computer

In Antigravity's **Review** pane, select the files that belong to the completed change and stage them. Choose **Commit**, write a short message describing the result, then choose **Push**. Check that the destination is your group's `origin/main`. If a different branch is selected, stop and agree the branch with the instructor before delivery. [Antigravity commit and push](https://antigravity.google/docs/review-changes/).

If your desktop version has different Git controls, its integrated terminal can do the same work from the project root. Inspect the list, then stage only the files belonging to this change; adjust the paths below if other files were intentionally changed:

```bash
git status
git diff
git add host/index.html host/server.js host/test.js
git commit -m "Describe the improvement"
git push origin main
git rev-parse --short HEAD
```

Use either the graphical commit/push or the terminal alternative. Open the group repository on GitHub and check that your new commit and files are there. Record its short commit ID; **a local commit alone is not delivered**.

## 2. On the Pi, stop and switch to TLU

At the Pi's own keyboard and monitor:

1. Stop the running Node server with **Ctrl+C** in its terminal.
2. Open the desktop's **Wi-Fi menu** and select the open network **TLU**. If the active hotspot must be disconnected first, use its disconnect action, then select TLU.
3. Check internet access by opening your GitHub repository in the Pi browser. Complete a network sign-in page if it appears.

While the Pi uses TLU, its group hotspot is unavailable. Arduino disconnecting at this point is expected. Do not change its firmware or Wi-Fi name to compensate.

## 3. Pull the reviewed version on the Pi

In the Pi terminal, from the existing clone:

```bash
cd ~/team-project
git status --short --branch
git pull --ff-only origin main
git rev-parse --short HEAD
```

Before pulling, the Pi copy should have no local file modifications. If it has any, stop and ask the instructor to help preserve and reconcile them. Do not overwrite them blindly. If pull reports a conflict or cannot fast-forward, resolve the reason before proceeding.

Compare the final commit ID with GitHub and the development copy. If it differs, check the repository URL, branch and push result. If Git says `Already up to date` but the change is missing, check these before editing anything on the Pi.

## 4. Return the Pi to the group hotspot

Use the **desktop Wi-Fi controls** again. Open the hotspot action, commonly under **Advanced Options → Create Wireless Hotspot**, and select/reactivate the **existing `ifi-lab` connection** for your group when offered. Menu wording varies with the installed desktop; the instructor demonstrates the saved-profile selection before the exercise. This step reuses the Session 4 profile rather than creating a new hotspot with different defaults.

Check that the Pi is now **hosting** the expected OPEN network, `IFI7386-G1` or `IFI7386-G2`, with hotspot address `10.42.0.1`. A phone or laptop should see that SSID. If the menu only offers a new hotspot, ask the instructor to restore the saved profile; do not accept an automatically generated password or changed address.

TLU should no longer be the active Wi-Fi connection. Stay in hotspot mode for the hardware test even though internet access is unavailable. Network changes are made through the GUI in this activity. [Raspberry Pi desktop networking](https://www.raspberrypi.com/documentation/computers/configuration.html#wireless-connection).

## 5. Start the updated server and test

From the Pi project root:

```bash
node host/server.js
```

Keep the terminal open. In the **Pi browser**, open **http://localhost:3000** and reload the page. A separate device must join the group hotspot and use **http://10.42.0.1:3000**. On separate Pis, both groups can use port 3000. If using the optional shared-Pi arrangement, keep the group-specific ports from [Session 4 setup](../../04-integration-and-collaborative-development/setup.md#optional-both-servers-on-one-computerpi).

Allow Arduino time to reconnect to the restored hotspot. Check its IP/HTTP 200 output. If it does not recover, reset it and use the [existing Wi-Fi diagnosis](../../04-integration-and-collaborative-development/wifi-troubleshooting.md). The server starts with empty in-memory state: wait for fresh seat messages or rescan a ticket.

Perform the change card's acceptance checks and one original main-path test with the physical input. Also test a relevant failure/recovery: for example unplug/reconnect the board, scan an unknown card, or stop/restart the host. Use the [Session 4 acceptance tests](../../04-integration-and-collaborative-development/testing.md) for expected baseline behaviour. Record pass/fail and the tested commit. If the change fails, return to the development computer, prompt a correction, review it and repeat this whole loop.

## If firmware changes later

Develop the `.ino` file in the development clone, review it, commit and push it with the project. Use Arduino IDE and USB on the development computer to upload the intended sketch to the board. A Git pull on the Pi downloads firmware **source** but does not flash the Arduino. If a change affects the data contract, test matching server and firmware versions and record both. Today's two core changes should preserve the working firmware.

## Quick fault checks

| Symptom | Check first |
|---|---|
| GitHub cannot be reached from Pi | Is Pi connected to TLU, and can its browser reach the repository? |
| Push rejected | Correct account and collaborator access? Another member pushed first? Coordinate, pull and reconcile before retrying; do not force-push. |
| Pi has the commit but the old behaviour remains | Running from `~/team-project`? Old process stopped? Updated server restarted? Browser reloaded? |
| Arduino cannot reach the updated Pi | Was the group hotspot restored with the original SSID, OPEN security and IP? |
| Server starts but no ticket route appears | Restart cleared the state: rescan a real mapped tag; check the mapping and reader heartbeat. |

Git help: [Push commits](https://docs.github.com/en/get-started/using-git/pushing-commits-to-a-remote-repository) · [Get remote changes](https://docs.github.com/en/get-started/using-git/getting-changes-from-a-remote-repository).

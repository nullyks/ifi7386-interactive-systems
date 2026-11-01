# Activity 01 — Group Repository and Two Clones

[Session 5](../README.md) · [Next activity](02-find-and-specify-improvements.md)

**Time: 25 minutes · One new GitHub repository per group**

## 1. Create your group repository

1. Choose one repository owner. On GitHub, select **New repository** and use a short project name, for example `ifi7386-library` or `ifi7386-ticket-guide`.
2. Choose visibility with the instructor. A public repository containing classroom example code is easiest to clone on the Pi; a private repository needs access set up on both computers. Add a README and create the repository. Use `main` as the default branch for today's instructions.
3. In the repository's **Settings → Collaborators** area, invite the other group members. They accept the invitation with their own GitHub accounts.

This is the group's project repository. Keep the course-materials repository as the source of teaching instructions.

## 2. Add your group's existing code

1. Find your working Session 4 files. If you need a fresh source, download the course repository using **Code → Download ZIP**, extract it, and locate your group's folder under `sessions/04-integration-and-collaborative-development/examples/`.
2. Copy the **contents of your group's application folder** into a separate staging folder. Include the whole `host` folder and both Arduino sketch folders. Keep your tested FSR thresholds or ticket mappings when available. Do not copy another repository's hidden `.git` folder.
3. Keep this layout at the root of the new repository:

| Group | Folders at repository root |
|---|---|
| 1 — Library | `host/`, `library/`, `library_serial/` |
| 2 — Ticket guidance | `host/`, `ticket/`, `ticket_serial/` |

The `.ino` file stays inside its same-named sketch folder. Do not upload only `server.js`: its HTML, tests, simulator and, for Group 2, `tickets.json` are needed too.

4. Keep the new repository's README and replace its text with a short project description, group members, the startup commands below and your actual SSID. The copied example README's `../../` teaching links would not work in this new location, so link to the course repository instead.
5. Include the course's `LICENSE` file and credit: **Original examples: Tanel Toova, 2026, IFI7386 course materials, CC BY 4.0; adapted by [your group].** Link to the [source repository](https://github.com/nullyks/ifi7386-interactive-systems) and name your later changes. Keep personal credentials out of project files.
6. On the new repository page, choose **Add file → Upload files**. Drag in the folders and licence, preserve the folder structure, and commit the upload with a message such as `Add working Session 4 prototype`. If uploading the copied README would overwrite your new one, leave that copied file out.

Open the GitHub file list. You should see `host/server.js` one level below the root, not inside another group folder. From now on, send code updates from the development Git copy using commit and push.

## 3. Clone on the development computer

Copy **your group's** HTTPS URL from GitHub's **Code** menu. In a terminal, move to the parent folder where you want the project and run the following, replacing the URL:

```bash
git clone https://github.com/YOUR-OWNER/YOUR-REPOSITORY.git team-project
cd team-project
git remote -v
git rev-parse --short HEAD
```

`team-project` is the local folder name used throughout this session. Choose a new folder rather than placing a repository inside the course repository. Check that `origin` points to your group, then open this folder in Antigravity during [Activity 03](03-develop-with-antigravity.md).

## 4. Clone on the Pi 400

At the Pi's keyboard and monitor, stop any existing Session 4 server with **Ctrl+C**. Keep its old folder as a reference; run the new clone for today's tests. Use the **desktop Wi-Fi menu** to connect to the open network **TLU**. The group hotspot stops while this connection is active. Confirm that the repository page opens in the Pi browser; complete any network sign-in page if one appears.

Open a terminal and run:

```bash
cd ~
git clone https://github.com/YOUR-OWNER/YOUR-REPOSITORY.git team-project
cd team-project
git remote -v
git rev-parse --short HEAD
```

Use the same group URL as on the development computer. Both clones should now show the same commit. Clone only once on each machine; use pull for later updates.

## 5. Check the baseline

In the **project root** on the development computer:

```bash
node --test host/test.js
node host/server.js
```

Open **http://localhost:3000**. Stop the server with **Ctrl+C** when finished. These examples need Node >=18 and no npm dependency installation.

On the Pi, use the desktop Wi-Fi controls to **reactivate the existing `ifi-lab` hotspot**, broadcasting your group's `IFI7386-G1` or `IFI7386-G2`. Follow [the hotspot return step](04-publish-update-and-test.md#4-return-the-pi-to-the-group-hotspot). Start `node host/server.js` from `~/team-project`, open **http://localhost:3000** on the Pi and repeat one known physical interaction. Check Arduino's HTTP 200 response.

If a baseline test fails, record the failure before changing anything. Group 2's supplied test assumes the sample UIDs and seats: replacing `tickets.json` with your actual cards can make that test fail even when physical guidance works. Ask the agent to explain this mismatch and agree a suitable test fixture with the instructor; preserve your real mapping.

**C1:** save your repository URL, both local folder locations, starting commit and baseline result. The Pi should be back in hotspot mode, ready for physical testing.

Source help: [Create a repository](https://docs.github.com/en/repositories/creating-and-managing-repositories/creating-a-new-repository), [upload files](https://docs.github.com/en/repositories/working-with-files/managing-files/adding-a-file-to-a-repository), [clone a repository](https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository).

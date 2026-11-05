# Activity 01 — Group Repository and Two Clones

[Session 5](../README.md) · [Next activity](02-find-and-specify-improvements.md)

**Time:** about 25 minutes after account/software preparation · **Format:** one new GitHub repository per group

## Goal

Create one group repository, connect both local copies and verify Git sign-in and the working prototype baseline.

## Before class: account and development software

The simplest classroom route is **a public group repository + HTTPS + Git for Windows with Git Credential Manager**. It uses browser sign-in and ordinary Git commands, which are also the commands an agent can use. You do not need GitHub Desktop, SSH keys or a manually created access token for this route.

### A. Create your own GitHub account

1. If you already have an account, sign in and use it. Otherwise open [github.com/signup](https://github.com/signup) and create a **free personal account**. You can choose **Continue with Google** if you already use that account for Antigravity, or follow the email/password signup.
2. Complete the account and email-verification steps shown by GitHub. Keep your username: the repository owner needs it to invite you.
3. Each group member uses their own account. Accept the owner's repository invitation before trying to push code. A public repository is readable by everyone, but only authorised collaborators can push.

[GitHub account-creation help](https://docs.github.com/en/account-and-profile/how-tos/account-management/creating-an-account-on-github).

### B. Windows development computer: install Git once

On the classroom computer or your Windows laptop, open **PowerShell** and check:

```powershell
git --version
git credential-manager --version
```

If both show a version, continue to Step 1 below. If either command is missing:

1. Download the normal installer from [Git for Windows](https://gitforwindows.org/).
2. Run it with the default options, including **Git Credential Manager** and command-line availability. Ask the instructor if the classroom computer requires installation rights.
3. Close and reopen PowerShell **and Antigravity**, then repeat the two checks. Restarting the apps lets them find the newly installed Git.

Git Credential Manager is included with Git for Windows; it handles the browser login in Step 3. [GitHub's HTTPS sign-in guidance](https://docs.github.com/en/get-started/git-basics/caching-your-github-credentials-in-git).

### Own Mac or Linux laptop: alternative to B

Check `git --version` first. If needed, install [Git for your operating system](https://git-scm.com/install/), then install [GitHub CLI (`gh`)](https://github.com/cli/cli#installation). For example, a Mac with Homebrew can use `brew install git gh`; a Debian/Ubuntu laptop can use `sudo apt update` followed by `sudo apt install git gh`. If your laptop needs a different installation method, use the linked official instructions with the instructor before class.

Run:

```bash
gh auth login
```

Choose **GitHub.com → HTTPS → authenticate Git: Yes → Log in with a web browser**, then complete the browser steps yourself. If the terminal shows a one-time code, enter it on the GitHub page it opens. Finish with:

```bash
gh auth setup-git
gh auth status
```

This configures ordinary Git to use the CLI's sign-in. Continue with the same repository/clone steps below; you will not need the Windows login window. [GitHub CLI login](https://cli.github.com/manual/gh_auth_login) · [Git credential-helper setup](https://cli.github.com/manual/gh_auth_setup-git).

## 1. Create your group repository

1. Choose one repository owner. On GitHub, select **New repository** and use a short project name, for example `ifi7386-library` or `ifi7386-ticket-guide`.
2. For the simplest class setup, choose **Public** for the classroom code, add a README and create the repository. Use `main` as the default branch for today's instructions. If your group needs a private repository, arrange its Pi access with the instructor before class; the no-login Pi steps below apply to public repositories.
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

### Clone and check the connection

On GitHub, open **your group's** repository, choose **Code → HTTPS** and copy its URL. On Windows, open your chosen parent folder, such as Documents, in File Explorer and use **Open in Terminal**. Run the following, replacing the whole example URL with the one you copied:

```bash
git clone https://github.com/YOUR-OWNER/YOUR-REPOSITORY.git team-project
cd team-project
git remote -v
git rev-parse --short HEAD
```

`team-project` is the new local folder used throughout this session. **Clone connects it to GitHub automatically:** `origin` is the name of that connection. Both fetch and push lines from `git remote -v` must show your group URL. You do not need `git init` or a separate remote-creation step.

Use a new folder outside the course repository. If your correct group clone already exists, enter it instead of cloning again. A downloaded ZIP is not a Git clone. A public clone normally needs no sign-in; that does not mean pushing is already configured.

### Set the author for this clone

While inside `team-project`, replace the two values below with your own name and commit email:

```bash
git config --local user.name "YOUR NAME"
git config --local user.email "YOUR COMMIT EMAIL"
```

Use a verified email from your GitHub account, or copy the exact GitHub-provided no-reply address from **GitHub profile picture → Settings → Emails**. Do not guess its spelling. These settings label your commits **in this clone only**; they do not sign you in. [Commit email help](https://docs.github.com/en/account-and-profile/how-tos/email-preferences/setting-your-commit-email-address).

### Sign Git into GitHub and check it

Still in the same folder, run this yourself in the terminal:

```bash
git push --dry-run origin main
```

On Windows, if sign-in is needed, choose the Git Credential Manager **browser sign-in** option, sign into your own GitHub account and complete any authorisation or verification prompt. Return to the terminal. If the correct account is already remembered, no window may appear.

Success is a result such as **Everything up-to-date**, without an authentication/permission error. `--dry-run` checks the attempted push without sending updates; your first real push happens after reviewing a change. [Git dry-run reference](https://git-scm.com/docs/git-push#Documentation/git-push.txt---dry-run).

Open this **same `team-project` folder** in Antigravity, as described in [Activity 03](03-develop-with-antigravity.md). Finish the initial browser login yourself before asking an agent to use Git. Signing into Antigravity does not sign Git into GitHub.

## 4. Clone on the Pi 400

At the Pi's keyboard and monitor, stop any existing Session 4 server with **Ctrl+C**. Keep its old folder as a reference; run the new clone for today's tests. Use the **desktop Wi-Fi menu** to connect to the open network **TLU**. The group hotspot stops while this connection is active. Confirm that the repository page opens in the Pi browser; complete any network sign-in page if one appears.

### Install Git on the Pi if needed

Open the Pi's **Terminal** and check:

```bash
git --version
```

If a version is shown, Git is already installed: skip the installation commands. If it says `git: command not found`, keep the Pi connected to **TLU** and run:

```bash
sudo apt update
sudo apt install git
git --version
```

Confirm installation with **Y** if asked. If `sudo` requests a password, use the Pi user's login password; typed characters are not displayed. A version number at the end confirms Git is available. These are the package-manager steps for Raspberry Pi OS; Node remains the separate [Session 4 preparation](../../04-integration-and-collaborative-development/setup.md#prepare-before-class). [Official Git installation guidance](https://git-scm.com/install/linux).

### Clone the public group repository

In that terminal, run:

```bash
cd ~
git clone https://github.com/YOUR-OWNER/YOUR-REPOSITORY.git team-project
cd team-project
git remote -v
git rev-parse --short HEAD
```

Use the same group URL as on the development computer. Both clones should now show the same commit. Clone only once on each machine; use pull for later updates.

**The Pi does not need a GitHub login or commit-author settings to clone and pull a public repository.** It is today's download/test machine; commit and push from the development computer. If the Pi asks for GitHub credentials, check that the URL is correct and the group repository really is public.

## 5. Check the baseline

In the **project root** on the development computer:

```bash
node --test host/test.js
node host/server.js
```

Open **http://localhost:3000**. Stop the server with **Ctrl+C** when finished. These examples need Node >=18 and no npm dependency installation.

On the Pi, use the desktop Wi-Fi controls to **reactivate the existing `ifi-lab` hotspot**, broadcasting your group's `IFI7386-G1` or `IFI7386-G2`. Follow [the hotspot return step](04-publish-update-and-test.md#4-return-the-pi-to-the-group-hotspot). Start `node host/server.js` from `~/team-project`, open **http://localhost:3000** on the Pi and repeat one known physical interaction. Check Arduino's HTTP 200 response.

If a baseline test fails, record the failure before changing anything. Group 2's supplied test assumes the sample UIDs and seats: replacing `tickets.json` with your actual cards can make that test fail even when physical guidance works. Ask the agent to explain this mismatch and agree a suitable test fixture with the instructor; preserve your real mapping.

**C1:** save your repository URL, both local folder locations, starting commit and baseline result. Confirm the development computer's author settings and dry-run push check. The Pi should have Git installed and be back in hotspot mode, ready for physical testing.

## Quick setup fixes

| Problem | What to do |
|---|---|
| `git` is not recognised on the development computer | Install Git, then reopen the terminal and Antigravity. |
| `Author identity unknown` when committing | Run the two local author-setting commands inside the group clone. This is separate from browser sign-in. |
| `Permission denied` or HTTP 403 on push | Check the group URL, the signed-in account and whether the collaborator invitation was accepted. |
| Windows asks for a GitHub password in the terminal instead of browser sign-in | Check that Git Credential Manager is installed. Use the browser-login route; ask the instructor to help repair the helper setup. |
| A previous student's GitHub account is being used | In Windows **Credential Manager → Windows Credentials**, remove the saved GitHub entry for that account with the instructor, then repeat the login check with the correct account. |
| The agent cannot push, but your terminal can | Use the same clone and native Git environment. Complete login yourself, then publish through the app's Review pane or terminal. |

On a shared classroom computer, sign out of your browser/Antigravity when finished and remove **your own** saved GitHub entry from Windows Credential Manager. Browser sign-out alone does not remove Git's remembered sign-in. Do not put passwords, access tokens or login codes in project files or agent prompts.

Source help: [Create a repository](https://docs.github.com/en/repositories/creating-and-managing-repositories/creating-a-new-repository), [upload files](https://docs.github.com/en/repositories/working-with-files/managing-files/adding-a-file-to-a-repository), [clone a repository](https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository).

## Output

C1: group repository URL, two clone locations, starting commit and baseline result; development author/sign-in check completed and Pi ready in hotspot mode.

---

[Session 5](../README.md) · [Glossary](../../../resources/glossary.md) · [Readings and references](../../../resources/academic-readings.md)

# Stage 2 — Pi host, transmission and browser

[Session 4](README.md)

**Student entry condition: first complete Stage 1 in your group guide.** You must already have reliable FSR readings/thresholds or actual RFID UIDs in Serial Monitor. Steps marked preparation are instructor work before class.

At minutes 55–70: join the prepared hotspot, start the supplied host, upload the NETWORK sketch, and inspect its JSON and HTTP 200 in Serial Monitor. At minutes 70–90: open the browser and verify visible feedback. The simulator below is optional troubleshooting, not your first exercise.

## Prepare before class

Each group has its OWN application folder and server. Prefer one Pi per group. Both Pis may use port 3000 and address 10.42.0.1 on their separate hotspots. G1 uses one board with two sensors. Separate boards per chair are an optional extension, each reporting only its unique seat ID. For one shared Pi/computer see the separate-port instructions below.

Use Raspberry Pi OS with NetworkManager (Bookworm or later). Work at the Pi keyboard/monitor or through Ethernet: hotspot activation disconnects existing Wi-Fi access. Set the correct Wi-Fi country in Raspberry Pi Configuration or `sudo raspi-config`. Check `nmcli device status` and `systemctl is-active NetworkManager`; commands below assume `wlan0`. Do not replace network management during class.

While still connected to internet, copy this entire session folder to the Pi (USB/file transfer), and install:

```bash
sudo apt update
sudo apt install nodejs npm
node --version
```

Use Node >=18. The host needs no downloaded npm dependencies. On programming laptops install Arduino IDE and **Arduino UNO R4 Boards** through Boards Manager. For Group 2, open **Sketch → Include Library → Manage Libraries...**, search for **AMRFID** by Guilherme Caiala, and install version **1.0.1** with its **MFRC522** dependency (tested here with **1.4.12**). Choose **Install all** if prompted; if MFRC522 is missing, install it separately. SPI and WiFiS3 come with board support. Resolve Wi-Fi firmware issues with Arduino's Firmware Updater before class.

## Hotspot (once per Pi)

At the Pi local keyboard, run the following for G1. If `ifi-lab` already exists, inspect/reuse it instead of duplicating it.

```bash
sudo nmcli device wifi hotspot ifname wlan0 con-name ifi-lab ssid IFI7386-G1 password 'PrototypeG1!'
sudo nmcli connection modify ifi-lab 802-11-wireless.band bg 802-11-wireless.channel 6 ipv4.method shared ipv4.addresses 10.42.0.1/24 ipv6.method disabled connection.autoconnect yes
sudo nmcli connection up ifi-lab
nmcli -f GENERAL,IP4 device show wlan0
```

For a separate G2 Pi, substitute SSID `IFI7386-G2` and password `PrototypeG2!` in the first command. Use channel 11 if needed to reduce interference. Confirm AP operation and address 10.42.0.1/24, then connect another device. Shared mode supplies client IP addresses. Separate hotspots can use the same subnet. Stay connected despite “no internet”; disable automatic network switching if necessary. Internet is not required after preparation.

To stop the hotspot later, locally run `sudo nmcli connection down ifi-lab`, then `sudo nmcli connection up 'YOUR_PREVIOUS_PROFILE'` using the actual former Wi-Fi profile name. This interrupts remote Wi-Fi access.

## Start host, then send real Arduino data

Choose ONLY your group's application and follow its own startup instructions:

- [Group 1 application and commands](examples/group-1-library/README.md): two FSR chairs, no ticket code.
- [Group 2 application and commands](examples/group-2-ticket/README.md): RFID tickets, no chair code.

Each application has its own `host/server.js`, `host/index.html`, `host/simulate.js`, `host/test.js` and `host/package.json`. Group 2 alone has `tickets.json`. There are no shared runtime files or packages. You may copy only your group's folder to its Pi.

On a separate Pi for each group, enter that group's `host` directory and run:

```bash
node server.js
```

Keep the terminal open. First upload your group's network sketch and look for HTTP 200 in Serial Monitor; then browse to **http://10.42.0.1:3000** from that Pi hotspot, or **http://localhost:3000** on the Pi. Stop with Ctrl+C. Restart after changing server code or Group 2 ticket mapping; reload the browser after editing HTML. Each server holds ONLY its own state in memory. Allow the lab port in any enabled firewall.

## Optional: both servers on one computer/Pi

Each server defaults to port 3000. Two processes cannot listen on the same port. In two terminals, enter the corresponding host directories and start:

```bash
# Terminal 1, in group-1-library/host:
node server.js
# Terminal 2, in group-2-ticket/host:
PORT=3001 node server.js
```

On Windows PowerShell, use `$env:PORT=3001` then `node server.js` in the Group 2 terminal instead. Open G1 at http://localhost:3000 and G2 at http://localhost:3001. For another device on the Pi hotspot use 10.42.0.1 instead of localhost.

For a SHARED Pi, both Arduino sketches must use that Pi's SSID/password/address, and G2 must change `SERVER_PORT` from 3000 to **3001**. G1 keeps 3000. The Group 2 simulator also needs the matching destination: on Pi run `HOST_URL=http://localhost:3001 node simulate.js ticket 04A1B2C3`; on PowerShell set `$env:HOST_URL='http://localhost:3001'` first. This is an optional hardware-saving arrangement; the main lesson assumes one Pi per group.

## Optional: isolate a host fault

Use only AFTER the serial-only checkpoint. Each group's own application README lists its simulator commands. Stop a running simulator before connecting real Arduino input, otherwise it can overwrite real readings/events. Simulation is not a substitute for actual sensor evidence.

## Upload and troubleshoot

Open the appropriate `.ino` in its same-named folder. Select **Arduino UNO R4 WiFi**, correct USB port, and check `WIFI_NAME`, `WIFI_PASSWORD`, `raspberryPiAddress` at the top. Upload; Serial Monitor **115200**. `HTTP/1.1 200 OK` means host accepted the message; Wi-Fi connection alone is insufficient.

| Symptom | First checks |
|---|---|
| Page unavailable | Correct hotspot/IP/:3000? Server open? Test localhost on Pi first |
| HOST_UNREACHABLE | Pi IP, running server, firewall and network |
| HTTP_TIMEOUT | Server responsiveness, network stability; next message retries |
| HTTP 400 | Compare JSON fields/types/IDs to contract |
| HTTP 404 | Endpoint spelling/method |
| EADDRINUSE | Another server already on 3000; stop old process |
| No Wi-Fi | Credentials, 2.4 GHz, country, Wi-Fi firmware, correct board |

After five minutes on one blocker use the instructor's prepared setup. Keep the verified local sensor sketch as a fallback. Use simulation only to isolate the later host stage, then reconnect actual input.

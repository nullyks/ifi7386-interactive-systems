# Stage 2 — Pi host, transmission and browser

[Session 4](README.md)

**Student entry condition: first complete Stage 1 in your group guide.** You must already have reliable FSR readings/thresholds or actual RFID UIDs in Serial Monitor. Steps marked preparation are instructor work before class.

At minutes 55–70: join the prepared hotspot, start the supplied host, upload the NETWORK sketch, and inspect its JSON and HTTP 200 in Serial Monitor. At minutes 70–90: open the browser and verify visible feedback. The simulator below is optional troubleshooting, not your first exercise.

## Prepare before class

Prefer one Pi per group. With one shared Pi use G1 credentials in BOTH sketches; one server supports both projects. G1 uses one board with two sensors. Separate boards per chair are an optional extension, each reporting only its unique seat ID.

Use Raspberry Pi OS with NetworkManager (Bookworm or later). Work at the Pi keyboard/monitor or through Ethernet: hotspot activation disconnects existing Wi-Fi access. Set the correct Wi-Fi country in Raspberry Pi Configuration or `sudo raspi-config`. Check `nmcli device status` and `systemctl is-active NetworkManager`; commands below assume `wlan0`. Do not replace network management during class.

While still connected to internet, copy this entire session folder to the Pi (USB/file transfer), and install:

```bash
sudo apt update
sudo apt install nodejs npm
node --version
```

Use Node >=18. The host needs no downloaded npm dependencies. On programming laptops install Arduino IDE, **Arduino UNO R4 Boards**, and **Adafruit PN532** plus **Adafruit BusIO**. WiFiS3 comes with board support. Resolve Wi-Fi firmware issues with Arduino's Firmware Updater before class.

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

Enter the copied session's `examples/host` folder; adapt this example path:

```bash
cd ~/04-integration-and-collaborative-development/examples/host
node server.js
```

Keep terminal open. Browse to **http://10.42.0.1:3000** from the Pi hotspot, or **http://localhost:3000** on Pi itself. Stop with Ctrl+C. Restart after changing `server.js` or `tickets.json`; reload browser after editing `index.html`. Server restart clears state until new messages arrive. Allow port 3000 on the lab interface if a firewall is enabled.

## Optional: isolate a host problem with simulated data

Use this only AFTER the sensor-only checkpoint if you need to distinguish a network/host fault from a sensor fault. It is not a substitute for actual readings. In a second terminal in the same directory:

```bash
node simulate.js library
```

L1 alternates; L2 stays free. Stop with Ctrl+C BEFORE real hardware, otherwise simulation overwrites real readings. After >10 seconds without reports seats become grey/unknown.

```bash
node simulate.js ticket 04A1B2C3
node simulate.js ticket 04112233
node simulate.js ticket FFFFFFFF
node simulate.js reader-error
```

The first two select different seats, the third shows unknown ticket, the fourth hardware error. These are sample UIDs until replaced by real ones. One-shot ticket simulation has no heartbeat, so reader goes offline after ten seconds. Real firmware sends two-second heartbeats. “Clear ticket display” clears this browser only; a new scan can show guidance again.

Equivalent request to inspect (Pi terminal):

```bash
curl -i http://localhost:3000/api/seats -H 'Content-Type: application/json' -d '{"v":1,"seats":[{"id":"L1","occupied":true,"raw":700},{"id":"L2","occupied":false,"raw":80}]}'
```

Expect HTTP 200 and `{"ok":true}`. Open `/api/state` to inspect what the browser receives. On another computer replace `localhost` with `10.42.0.1`. Host/UI development also works locally on a laptop with Node; the intended physical integration uses Pi.

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

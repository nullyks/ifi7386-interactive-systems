# Group 1 — Library seats

[Session 4](../../README.md) · [Group activity](../../group-1-library.md) · [Pi hotspot preparation](../../setup.md)

This folder is a COMPLETE independent example. Copy this folder to your group's Pi and programming laptop as needed. No files from the other group are required. Node >=18; no npm dependency installation required.

## 1. Arduino and real input first

Open `library_serial/library_serial.ino`, select UNO R4 WiFi and correct USB port, upload and open Serial Monitor at 115200. Complete calibration / actual UID collection using the group activity guide before starting network work.

## 2. Start your own server

On Pi enter your copied folder's host directory (adapt this path):

```bash
cd ~/group-1-library/host
node server.js
```

Keep terminal open. Stop with Ctrl+C. The server defaults to port 3000 on all network interfaces.

## 3. Transmit real data

Open `library/library.ino`. Check Wi-Fi settings and Pi address. Copy your FOUR measured thresholds from the serial-only sketch. Upload and inspect outgoing JSON and HTTP 200 in Serial Monitor.

## 4. Open your page

On a browser joined to YOUR Pi hotspot open http://10.42.0.1:3000, or on Pi itself http://localhost:3000. Your server serves its own `host/index.html`.

The page shows ONLY two library chairs. No RFID or ticket code is needed.

Optional host test, in a second terminal in this same host folder:

```bash
node simulate.js
```

L1 alternates occupied/free; L2 remains free. Stop with Ctrl+C before using Arduino. After ten seconds without messages both seats become unknown.

## Files you may change

- `library_serial/library_serial.ino`: local sensor reading and Serial Monitor only.
- `library/library.ino`: the same reading plus Wi-Fi/HTTP.
- `host/server.js`: receives and validates your group's data.
- `host/index.html`: your group's drawing, labels and browser behaviour.
- `host/simulate.js`: optional fault-isolation requests.
- `host/test.js`: instructor/support checks; run `npm test` inside host.

Group 1 POST route: /api/seats. State contains only seats. Both use GET / for HTML and GET /api/state for browser updates. The other group's routes are deliberately unavailable.

If both servers run on one computer, Group 2 must use port 3001; see [shared-machine instructions](../../setup.md). On separate Pis both groups keep port 3000. Reload after changing HTML; restart after server changes. Then run [acceptance tests](../../testing.md).

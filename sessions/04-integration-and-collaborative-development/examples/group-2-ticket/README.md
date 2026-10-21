# Group 2 — Ticket guidance

[Session 4](../../README.md) · [Group activity](../../group-2-ticket.md) · [Pi hotspot preparation](../../setup.md)

This folder is a COMPLETE independent example. Copy this folder to your group's Pi and programming laptop as needed. No files from the other group are required. Node >=18; no npm dependency installation required.

Hardware: **RFID-RC522 V1.33 + Arduino UNO R4 WiFi**, using the instructor-tested direct wiring without a logic-level shifter. Power the reader from **3.3 V**. Follow the [pin-by-pin wiring table](../../group-2-ticket.md#parts-and-wiring): SDA/SS→D10, RST→D9, SCK→D13, MOSI→D11, MISO→D12, GND→GND; IRQ is unused.

## 1. Arduino and real input first

In Arduino IDE Library Manager, install **AMRFID 1.0.1** by Guilherme Caiala and its **MFRC522** dependency (tested with **1.4.12**); choose **Install all** if prompted. Open `ticket_serial/ticket_serial.ino`, select UNO R4 WiFi and the correct USB port, upload and open Serial Monitor at **115200**. The initialisation message confirms that the program started; a real `UID: ...` line confirms the reader works. Record the actual UIDs of 2–3 cards using the group activity guide before starting network work. Keep leading zeros and remove the card before scanning it again.

## 2. Start your own server

On Pi enter your copied folder's host directory (adapt this path):

```bash
cd ~/group-2-ticket/host
node server.js
```

Keep terminal open. Stop with Ctrl+C. The server defaults to port 3000 on all network interfaces.

If the Arduino cannot join the Pi hotspot, use [Wi-Fi diagnosis](../../wifi-troubleshooting.md) before changing RFID code. The separate Wi-Fi check needs no reader, RFID library or server. Confirm the Arduino can see the hotspot and obtain an IP address; a phone connection alone does not verify the Arduino connection.

## 3. Transmit real data

Open `ticket/ticket.ino`. Check `WIFI_NAME` and the Pi address. The Pi hotspot uses **OPEN Wi-Fi**, so the sketch calls `WiFi.begin(WIFI_NAME)` with no password. Keep your actual UIDs ready for the mapping file. Upload and inspect outgoing JSON and HTTP 200 in Serial Monitor.

## 4. Open your page

On a browser joined to YOUR Pi hotspot open http://10.42.0.1:3000, or on Pi itself http://localhost:3000. Your server serves its own `host/index.html`.

The page shows ONLY reader status, seat selection and route directions. No FSR/chair code is needed.

"Reader initialised; scan a card to check" means the Arduino is sending heartbeats after calling `reader.begin()`. AMRFID does not report initialisation success or a disconnected reader, so confirm operation by scanning a known card.

Replace sample UID keys in `host/tickets.json` with the ACTUAL UIDs saved during Stage 1. Restart the server after editing this mapping. Open the page and rescan a real tag.

Optional host tests, from a second terminal in this same host folder:

```bash
node simulate.js ticket 04A1B2C3
node simulate.js ticket 04112233
node simulate.js ticket FFFFFFFF
node simulate.js reader-error
```

Use your actual mapped UID if you changed the file. Known sample tickets select A2/B3; an unknown tag clears the previous route; `reader-error` simulates an explicit reader error report (the AMRFID sketches cannot detect this automatically). One-shot simulation has no heartbeat and goes offline after ten seconds. Actual firmware sends heartbeats. Guidance expires after 15 seconds. “Clear ticket display” affects only this browser.

## Files you may change

- `ticket_serial/ticket_serial.ino`: local sensor reading and Serial Monitor only.
- `ticket/ticket.ino`: the same reading plus Wi-Fi/HTTP.
- `host/server.js`: receives and validates your group's data.
- `host/index.html`: your group's drawing, labels and browser behaviour.
- `host/simulate.js`: optional fault-isolation requests.
- `host/test.js`: instructor/support checks; run `npm test` inside host.

Group 2 POST routes: /api/ticket and /api/reader. State contains only reader and ticket. Both use GET / for HTML and GET /api/state for browser updates. The other group's routes are deliberately unavailable.

If both servers run on one computer, Group 2 must use port 3001; see [shared-machine instructions](../../setup.md). On separate Pis both groups keep port 3000. Reload after changing HTML; restart after server or ticket mapping changes. Then run [acceptance tests](../../testing.md).

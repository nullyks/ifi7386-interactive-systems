# Group 2 — Ticket to seat and route

[Session 4](README.md) · [Setup](setup.md) · [Stage 1: serial-only sketch](examples/group-2-ticket/ticket_serial/ticket_serial.ino) · [Stage 2: network sketch](examples/group-2-ticket/ticket/ticket.ino) · [Mapping](examples/group-2-ticket/host/tickets.json)

## Parts and wiring

Use one **RFID-RC522 V1.33**, one **Arduino UNO R4 WiFi**, compatible cards/tags, jumper wires and a USB data cable. This class uses the instructor-tested direct connection without a logic-level shifter. The table below is for this classroom kit. Disconnect USB before changing wires.

| UNO R4 WiFi | RC522 pin | Purpose |
|---|---|---|
| 3.3 V | 3.3V | Reader power; use 3.3 V, not 5 V |
| GND | GND | Common ground |
| D10 | SDA / SS | Select the reader for SPI communication |
| D13 | SCK | SPI clock |
| D11 | MOSI | Data from Arduino to reader |
| D12 | MISO | Data from reader to Arduino |
| D9 | RST | Reset the reader |
| Leave disconnected | IRQ | Not used in this example |

**The reader's SDA label means SS (chip select) in this SPI example. Connect it to D10, not to the Arduino pin labelled SDA.** Find pins by their printed labels, not by their physical order in an online photo. Both supplied sketches use SS=D10 and RST=D9.

## Stage 1 — Arduino and reader ONLY (minutes 10–45)

1. In Arduino IDE, open **Sketch → Include Library → Manage Libraries...**. Install **AMRFID 1.0.1** by Guilherme Caiala and its **MFRC522** dependency (tested with **1.4.12**). Choose **Install all** if prompted. Then open `examples/group-2-ticket/ticket_serial/ticket_serial.ino`; select **Arduino UNO R4 WiFi** and the correct USB port. This sketch has NO network code.
2. Upload and open Serial Monitor at **115200**. Expect `READER_INITIALISED: scan a card to check the reader.` This means the program has called `reader.begin()`; AMRFID does not report whether the reader responded. A real UID in the next step confirms the reader works.
3. Scan a compatible 13.56 MHz ISO14443A tag; a 125 kHz tag will not work. Remove it for at least two seconds before scanning the same one again. Read the uppercase hex UID, preserving zeros, without spaces.
4. Label 2–3 tags and record their ACTUAL UIDs on paper/shared log. Decide destinations A2, B3, C1. Scan each three times. **C1:** demonstrate reliable local UIDs before using Pi.

### Read the short sensor code

`AMRFID reader(READER_SS_PIN, READER_RST_PIN)` creates the reader object with its two configurable pins. `reader.begin()` starts SPI and initialises the reader. `reader.lerUID()` means "read UID": this is the library's actual method name, so keep its spelling. It returns uppercase hexadecimal text such as `04A1B2C3`, including leading zeros, or empty text (`""`) when no new card could be read. `readNewCard()` is our English-named helper that prints and returns that result. Keep the card-to-seat mapping on the Pi; do not add an allowed-card list to the Arduino.

| Symptom | Check |
|---|---|
| `AMRFID.h: No such file or directory` | Install AMRFID in Library Manager |
| `MFRC522.h: No such file or directory` | Install the MFRC522 dependency |
| Unreadable Serial Monitor text | Set the speed to 115200 |
| Initialisation message but no UID | Check 3.3 V, GND, SDA→D10, RST→D9 and the three SPI wires; try a supplied compatible card |
| The same card does not scan again | Remove it from the reader, wait at least two seconds, then present it again |

After correcting wiring with USB disconnected, reconnect USB and reset or upload again. This example does not automatically detect a disconnected reader or retry initialisation.

## Stage 2 — Send a scan, THEN show seat/route (minutes 45–90)

1. Turn one actual UID into a [JSON message](data-contract.md).
2. Follow [Pi setup](setup.md): join hotspot and start host.
3. Open `examples/group-2-ticket/ticket/ticket.ino`. Check G2 credentials. If sharing the G1 Pi, use its credentials AND set `SERVER_PORT = 3001` while starting your own server with `PORT=3001` (see setup). Upload. Scan a tag and inspect outgoing UID JSON plus HTTP 200 in Serial Monitor (**C2**).
4. Replace sample KEYS in `examples/group-2-ticket/host/tickets.json` with your saved UIDs and destinations. Keep valid JSON, no trailing comma. The bundled UIDs are examples and will probably not match your cards. Restart host after saving.
5. Open http://10.42.0.1:3000. Scan each tag and check correct seat, path and written directions. Scan an unregistered tag: previous route must disappear. **C3:** physical card selects its actual mapped seat.

No writing to cards is required: host looks up UID. Keep names out of mappings. UID matching is a classroom demonstration, not secure authentication.

## Behaviour and limitations

AMRFID halts the card after reading its UID, so a card held at the reader should not repeatedly create new events. Remove it for at least two seconds before presenting it again. Another card can be read next. Test this with the actual kit; inspect logs and card positioning if reads repeat or are missed.

Latest scan replaces the previous one. Guidance clears after 15 seconds; reader becomes offline after ten seconds without messages. Two-second heartbeats distinguish idle reader from disconnected board. Failed scan delivery retries the latest pending UID for approximately five seconds, then discards it; after an outage ask the visitor to rescan. This is not a persistent queue or exactly-once delivery. Network requests can delay reading.

AMRFID's `begin()` returns no success flag, and an empty `lerUID()` result does not distinguish "no new card" from a read failure. The firmware sends `ready: true` after initialisation; this means the initialisation code ran, not that hardware health was verified. The heartbeat proves the Arduino is reachable. A disconnected RC522 may therefore leave the board online with no scans. The browser says "Reader initialised; scan a card to check." Verify with a known card, reconnect with power off, and reset the board. The optional `reader-error` simulator demonstrates an explicit error report; this firmware does not generate that report automatically.

After core works add a third ticket, improve route text or adapt the plan. Routes start at one fixed entrance through the centre aisle; edit geometry AND written instructions together for a different layout. This is not live positioning. Ask a peer to follow directions from the drawn entrance. [Run acceptance tests](testing.md).

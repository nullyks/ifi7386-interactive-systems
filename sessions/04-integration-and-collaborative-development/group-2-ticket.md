# Group 2 — Ticket to seat and route

[Session 4](README.md) · [Setup](setup.md) · [Stage 1: serial-only sketch](examples/ticket_serial/ticket_serial.ino) · [Stage 2: network sketch](examples/ticket/ticket.ino) · [Mapping](examples/host/tickets.json)

## Confirm reader and electrical compatibility

The ASIN is listed elsewhere as PN532 V2 / XD045, with SPI/I2C/HSU. Amazon could not be verified. This example assumes PN532 in SPI mode, not RC522. Before class confirm actual module/chip markings, supplier pinout, supply and logic voltage, and mode-selector legend. Use its own SPI switch/jumper table with power off; do not copy positions from another revision. Power-cycle after selection.

UNO R4 headers use 5 V logic. A module's 5 V power input does NOT establish signal tolerance. Unless the exact module documents full compatibility, use a verified SPI-capable level translator for both directions. A slow generic I2C shifter is not automatically suitable. Have the instructor prepare the adapter before class.

| UNO | PN532 | Signal direction |
|---|---|---|
| D13 | SCK / SCLK | UNO → reader; translate |
| D11 | MOSI | UNO → reader; translate |
| D10 | SS / SSEL / CS | UNO → reader; translate |
| D12 | MISO | Reader → UNO; translate to valid UNO logic level |
| GND | GND | Common ground |
| Appropriate regulated supply | VCC | Exact module's documented voltage/current |

Connect translator reference rails, enable and direction according to its documentation (high side UNO 5 V; low side reader logic rail). Do not connect two power outputs together. The supplied ASIN does not establish the actual module's supply pin specification: instructor must resolve that preflight. Use a verified adapter or host simulation if documentation is missing; do not guess voltages during class. Software SPI needs no IRQ connection here.

## Stage 1 — Arduino and reader ONLY (minutes 10–45)

1. Install Adafruit PN532 plus BusIO beforehand. Open `examples/ticket_serial/ticket_serial.ino`; select UNO R4 WiFi and correct USB port. This sketch has NO network code.
2. Upload. At Serial Monitor **115200** expect READER_READY. READER_NOT_FOUND means check power, mode, ground, wiring and translation. Initialization retries every five seconds after failure.
3. Scan a compatible 13.56 MHz ISO14443A tag; a 125 kHz tag will not work. Remove it for at least two seconds before scanning the same one again. Read the uppercase hex UID, preserving zeros, without spaces.
4. Label 2–3 tags and record their ACTUAL UIDs on paper/shared log. Decide destinations A2, B3, C1. Scan each three times. **C1:** demonstrate reliable local UIDs before using Pi.

## Stage 2 — Send a scan, THEN show seat/route (minutes 45–90)

1. Turn one actual UID into a [JSON message](data-contract.md).
2. Follow [Pi setup](setup.md): join hotspot and start host.
3. Open `examples/ticket/ticket.ino`. Check G2 credentials; use G1 credentials if sharing that Pi. Upload. Scan a tag and inspect outgoing UID JSON plus HTTP 200 in Serial Monitor (**C2**).
4. Replace sample KEYS in `host/tickets.json` with your saved UIDs and destinations. Keep valid JSON, no trailing comma. The bundled UIDs are examples and will probably not match your cards. Restart host after saving.
5. Open http://10.42.0.1:3000. Scan each tag and check correct seat, path and written directions. Scan an unregistered tag: previous route must disappear. **C3:** physical card selects its actual mapped seat.

No writing to cards is required: host looks up UID. Keep names out of mappings. UID matching is a classroom demonstration, not secure authentication.

## Behaviour and limitations

Held duplicate cards are suppressed by last UID/removal interval; another card can be read immediately. Intermittent RF readings can trigger repeat events with this simple removal heuristic. Inspect logs and card positioning first.

Latest scan replaces the previous one. Guidance clears after 15 seconds; reader becomes offline after ten seconds without messages. Two-second heartbeats distinguish idle reader from disconnected board. Failed scan delivery retries the latest pending UID for approximately five seconds, then discards it; after an outage ask the visitor to rescan. This is not a persistent queue or exactly-once delivery. Network requests can delay reading.

Startup hardware failure is detected. Runtime reader removal may look like “no card” because this read API does not reliably distinguish them; ready does not continuously prove antenna health. Document the limitation, reconnect safely with power off, and reset board.

After core works add a third ticket, improve route text or adapt the plan. Routes start at one fixed entrance through the centre aisle; edit geometry AND written instructions together for a different layout. This is not live positioning. Ask a peer to follow directions from the drawn entrance. [Run acceptance tests](testing.md).

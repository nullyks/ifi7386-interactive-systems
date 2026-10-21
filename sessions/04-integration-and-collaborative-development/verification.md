# Verification and sources

Prepared 18 October 2026. Group 2 updated and rechecked 21 October 2026 for RFID-RC522 V1.33 with AMRFID.

## OPEN Wi-Fi update — 21 October 2026

- The requested classroom configuration is now **Wi-Fi security: OPEN**. Both application sketches and the standalone Wi-Fi check use `WiFi.begin(WIFI_NAME)` with no password argument or password variable. The diagnostic scan labels an unsecured network `OPEN` and reports `TARGET_NOT_OPEN` if the target SSID is secured.
- The Pi guide creates a new AP profile without a wireless-security setting. Its separate migration block removes the entire `802-11-wireless-security` setting from an existing protected profile before restarting it, clearing the previous PSK/WPA configuration. No password-generating hotspot shortcut is used.
- All current student instructions, both group guides and the Wi-Fi troubleshooting steps now follow the OPEN setup. Network names, 2.4 GHz channels and the Pi address remain the same. Sensor/UID helpers were compared with the preceding commit and are unchanged. Local teaching links resolve.
- All three OPEN-network sketches compile for `arduino:renesas_uno:unor4wifi` with Arduino UNO R4 Boards **1.5.3**. The ticket sketch uses AMRFID **1.0.1** and MFRC522 **1.4.12**; the existing MFRC522 architecture-metadata warning remains.

| Current sketch | Flash bytes | RAM bytes |
|---|---|---|
| library | 63,100 | 7,588 |
| ticket | 70,716 | 8,044 |
| wifi_check | 60,888 | 7,528 |

- The WiFiS3 source confirms that the one-argument `begin(ssid)` overload selects the no-passphrase connection path. The profile-removal command was checked against the NetworkManager command reference. Actual Pi profile activation and Arduino radio connection still require checks on the physical kit; the earlier classroom fault remains unconfirmed.

## Earlier Wi-Fi follow-up — 21 October 2026

This section records the earlier protected-network setup and compile results, superseded by the OPEN update above.

Both groups reported Arduino connection failure on fresh Pi installations; a phone could connect. No Arduino connection output, active Pi security settings or Pi logs were available for diagnosis. The cause of that physical failure remains unconfirmed.

- That revision explicitly configured 2.4 GHz, channel 6/11, WPA2/RSN with CCMP and PMF disabled, and required an Arduino IP checkpoint. This was a compatibility baseline to test, not evidence that WPA3 or PMF caused the incident. The current guide uses OPEN Wi-Fi instead.
- WiFiS3's `begin()` in board package 1.5.3 waits up to ten seconds by default. Both application sketches previously started their retry timer before that blocking call; they now start it after the call returns, leaving ten seconds between attempts. Both print the target SSID, firmware version, connection result and successful connection's IP/signal.
- A standalone `examples/wifi_check/wifi_check.ino` scans for the configured SSID, reports channel/security/signal, firmware and MAC address, makes one twenty-second connection attempt, and then reports current status/IP. It needs no sensors, RFID library or host application.
- All three final sketches compile for `arduino:renesas_uno:unor4wifi` with Arduino UNO R4 Boards **1.5.3**. The ticket sketch uses AMRFID **1.0.1** and MFRC522 **1.4.12**; the dependency's architecture-metadata warning remains as described below.

| Sketch at that revision | Flash bytes | RAM bytes |
|---|---|---|
| library | 63,068 | 7,588 |
| ticket | 70,676 | 8,044 |
| wifi_check | 60,776 | 7,528 |

- Source comparison confirmed that the sensor-reading/message helpers are unchanged and both application Wi-Fi helpers match. Local teaching links resolve.
- No Pi commands were executed on a real Pi in this follow-up, and no physical Arduino Wi-Fi connection or recovery was tested. The [diagnosis guide](wifi-troubleshooting.md) records the missing evidence and next hardware checks. Compilation does not confirm radio interoperability or that the reported fault is fixed.

## RC522 update — 21 October 2026

The compile figures in this section describe the RC522 migration before the Wi-Fi follow-up above.

- Both Group 2 sketches compile for `arduino:renesas_uno:unor4wifi` with Arduino UNO R4 Boards **1.5.3**, **AMRFID 1.0.1** and **MFRC522 1.4.12**. SPI and WiFiS3 are provided by the board package. Library downloads were kept outside the repository; no library source was modified.

| Sketch | Flash bytes | RAM bytes |
|---|---|---|
| ticket_serial | 60,436 | 7,200 |
| ticket | 69,388 | 8,032 |

- MFRC522 emits an architecture warning because its metadata does not list `renesas_uno`. Both compilations nevertheless succeed. This is a compile check, not a new physical hardware test.
- The Group 2 HTTP integration test passes on Node **24.19.0**: known/unknown UID, invalid messages, reader error reports, expiry and isolation from Group 1. The server and JSON request shapes are unchanged.
- Both sketches use the same commented `startReader()` and `readNewCard()` helpers. AMRFID's `lerUID()` reads and formats the UID and halts the card. The former byte conversion and elapsed-time duplicate filter have been removed.
- AMRFID's `begin()` returns no success flag. The initialisation message and `ready: true` heartbeat now mean that the initialisation code ran; they do not claim successful hardware detection. Browser wording, the data contract, troubleshooting and acceptance guidance describe this limitation. `reader-error` remains an optional simulated error report.
- The instructor reports that the classroom RC522 V1.33 / UNO R4 WiFi kit works with direct signal wiring without a level shifter. The new pin table reflects that kit, uses **3.3 V power**, and explicitly distinguishes the RC522's SDA/SS pin (D10) from Arduino SDA. Physical card reading, held-card behaviour, Wi-Fi transmission and end-to-end recovery still need to be checked with the updated sketches on the actual kit.

## Earlier checks — 18 October 2026

- The unchanged Group 1 sketches compiled for arduino:renesas_uno:unor4wifi with Arduino UNO R4 Boards 1.5.3. The current Group 2 compile results are recorded above.

| Sketch | Flash bytes | RAM bytes |
|---|---|---|
| library_serial | 52,320 | 6,756 |
| library | 61,828 | 7,576 |

- Node 24.15.0: both independent host integration tests pass. Each rejects the other group’s endpoints with HTTP 404 and exposes only its own state. Covered behaviour: initial unknown, occupied/free, malformed JSON, invalid version/ID/type/range, duplicate IDs, no partial state update on invalid message, known/unknown UID, reader error and stale expiry.
- Browser check with two independent local hosts (G1 port 3000, G2 port 3001) and simulated HTTP requests: initial unknown state, L1 occupied/raw 700, L2 free/raw 80, reader ready, seat A2 and corresponding written route displayed. Physical input was NOT used for this check.
- Browser code expanded into named functions; hall geometry is plain SVG. Clear-ticket logic uses host scan identity instead of comparing browser and Pi clocks.
- Repository-local teaching links checked. ZIP includes two independent application folders, each with its own serial/network sketches, host, page, simulator, tests and startup README.
- Actual sensor mounting, Wi-Fi AP and physical end-to-end recovery still require checks on the real kits before class.

## What changed for beginners

Stage 1 has separate serial-only sketches with no networking. Stage 2 repeats the same sensor functions and adds commented Wi-Fi/HTTP helpers. Explicit names and if/else replace compressed expressions. Server, page, simulator and test code are expanded and commented. The shared runtime has been removed; G1 has no ticket mapping or reader code and G2 has no library seat logic. Comments explain syntax, data flow and where values should be edited. Student instructions and instructor timing now follow local input → transmission → browser feedback. Simulation is optional later fault isolation.

## Sources and assumptions

- [Official UNO R4 WiFi documentation](https://docs.arduino.cc/hardware/uno-r4-wifi/) and [WiFiS3 source documentation](https://github.com/arduino/docs-content/blob/main/content/hardware/uno/boards/uno-r4-wifi/tutorials/wifi-examples/wifi-examples.md): board/networking and bundled WiFiS3.
- [Official pinout](https://docs.arduino.cc/resources/pinouts/ABX00087-full-pinout.pdf): pins and electrical context; verify peripheral tolerances separately.
- [Raspberry Pi configuration](https://www.raspberrypi.com/documentation/computers/configuration.html): NetworkManager hotspot approach; supplied steps explicitly set a fixed subnet.
- [AMRFID source and API](https://github.com/guicaiala/AMRFID): constructor, `begin()` and `lerUID()`. The released 1.0.1 source was inspected: uppercase UID formatting with leading zeros, empty text on no new card/read failure, card halt after reading, and no initialisation success result.
- [MFRC522 driver](https://github.com/miguelbalboa/rfid): the dependency used by AMRFID. The software API does not establish the electrical tolerance of every RC522 module revision; direct wiring here is based on the instructor's tested classroom kit.
- [Node HTTP API](https://nodejs.org/api/http.html): built-in server, no external host dependencies.

The original example code accompanies the course licence; linked libraries retain their own licences. One UNO reads both chairs; one Pi per group preferred; separate ports required if using one Pi. Displays are browser interfaces, with static routes from one entrance.

## Three-table library view

The Group 1 map contains independent 2-, 4- and 6-seat areas with their own descriptions. Browser checks confirmed mouse opening for Tables 2/3, close-button/Escape behaviour and keyboard activation. Simulated POST still updates L1 red and L2 green; added chairs stay white/dashed and unmeasured. Group 1 API regression test passes. Arduino and server code were unchanged.

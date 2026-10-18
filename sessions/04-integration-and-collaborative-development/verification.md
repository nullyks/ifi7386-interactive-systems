# Verification and sources

Prepared 18 October 2026.

## Checks actually completed (beginner revision)

- Four sketches compile for arduino:renesas_uno:unor4wifi with Arduino UNO R4 Boards 1.5.3. PN532 examples use Adafruit PN532 1.3.4 and BusIO 1.17.4.

| Sketch | Flash bytes | RAM bytes |
|---|---|---|
| library_serial | 52,320 | 6,756 |
| ticket_serial | 66,364 | 9,364 |
| library | 61,828 | 7,576 |
| ticket | 75,372 | 10,192 |

- Node 24.15.0 HTTP integration test passes: initial unknown, occupied/free, malformed JSON, invalid version/ID/type/range, duplicate IDs, no partial state update on invalid message, known/unknown UID, reader error and stale expiry.
- Browser check with local host and simulated HTTP requests: initial unknown state, L1 occupied/raw 700, L2 free/raw 80, reader ready, seat A2 and corresponding written route displayed. Physical input was NOT used for this check.
- Browser code expanded into named functions; hall geometry is plain SVG. Clear-ticket logic uses host scan identity instead of comparing browser and Pi clocks.
- Repository-local teaching links checked. ZIP includes four sketches and all revised teaching/host files.
- Actual sensor mounting, RFID electrical compatibility, Wi-Fi AP and physical end-to-end recovery still require checks on the real kits before class.

## What changed for beginners

Stage 1 has separate serial-only sketches with no networking. Stage 2 repeats the same sensor functions and adds commented Wi-Fi/HTTP helpers. Explicit names and if/else replace compressed expressions. Server, page, simulator and test code are expanded and commented. Comments explain syntax, data flow and where values should be edited. Student instructions and instructor timing now follow local input → transmission → browser feedback. Simulation is optional later fault isolation.

## Sources and assumptions

- [Official UNO R4 WiFi documentation](https://docs.arduino.cc/hardware/uno-r4-wifi/) and [WiFiS3 source documentation](https://github.com/arduino/docs-content/blob/main/content/hardware/uno/boards/uno-r4-wifi/tutorials/wifi-examples/wifi-examples.md): board/networking and bundled WiFiS3.
- [Official pinout](https://docs.arduino.cc/resources/pinouts/ABX00087-full-pinout.pdf): pins and electrical context; verify peripheral tolerances separately.
- [Raspberry Pi configuration](https://www.raspberrypi.com/documentation/computers/configuration.html): NetworkManager hotspot approach; supplied steps explicitly set a fixed subnet.
- [Adafruit PN532 library and API](https://github.com/adafruit/Adafruit-PN532): software SPI constructor and bounded UID reads. This establishes driver API, not third-party board voltage tolerance.
- [Node HTTP API](https://nodejs.org/api/http.html): built-in server, no external host dependencies.
- [Supplied Amazon item](https://www.amazon.de/dp/B0FKH38Z6H) was inaccessible. [Secondary ASIN listing](https://www.odkarla.cz/sada-pn532-nfc-rfid-modulu-v2-nfc-ctecka-pro-kompatibilitu-podporuje-i2c-spi-hsu-s-dosahem-az-7~p2094865) identifies PN532 V2 / XD045. Treat identification as provisional and inspect actual module/supplier pinout before powering.

The original example code accompanies the course licence; linked libraries retain their own licences. One UNO reads both chairs; one Pi per group preferred, shared Pi supported. Displays are browser interfaces, with static routes from one entrance.

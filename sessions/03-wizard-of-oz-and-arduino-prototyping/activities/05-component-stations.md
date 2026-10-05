# Activity 05 - Component Stations

[← Session 3](../README.md) · [← Previous activity](04-button-to-led-loop.md)

**Time:** 20 minutes · **Format:** guided component comparison

## Goal

Compare four practical Arduino routes for a project interaction: sensing, physical visual feedback, movement, and a browser-based interface. Identify the hardware and constraints before selecting a Hi-Fi slice.

## Part 1 - Visit the four options (16 minutes)

Spend about four minutes on each category. Inspect available components, source diagrams, or an instructor-prepared demo. Do not try to build every option. Add a note where the option might fit your project.

| Category | Examples | Ask whether it fits | Main constraints to check |
|---|---|---|---|
| **Sensors and input** | Force or bend, temperature, distance, motion, humidity, soil moisture | What user action or environmental event must the system detect? | Calibration, placement, range, noisy or missing readings; a reading does not automatically reveal a person's intent. |
| **Screens and LED elements** | Seven-segment display, RGB LED, LCD, TFT, OLED, NeoPixel | What information or feedback must a person see, at what distance, and with how much detail? | Available display, pins or interface, library, readability, power, current-limiting resistors, and for LED arrays, total current. |
| **Motors and movement** | DC motor, servo, stepper motor | Does the interaction need continuous rotation, a target angle, or controlled steps? | Load, suitable driver, rated external supply, common ground, moving parts, and safe stopping. |
| **Browser interface on UNO R4 WiFi** | Local web page opened on a phone or computer; buttons or switches change a board state | Would a familiar browser interface help the user control the prototype or inspect its status? | Requires an **Arduino UNO R4 WiFi** (not UNO R3 or UNO R4 Minima), the board package and aWOT library. The board can create its own local Wi-Fi network; internet access is not required for the example. |

Source material: [Arduino sensors](https://github.com/nullyks/Arduino-erinevad-andurid); [screens and LED elements](https://github.com/nullyks/Arduino-ekraanid-ja-led-elemendid); [motors and power](https://github.com/nullyks/Arduino-mootorid-ja-toide); [UNO R4 WiFi web server and interface](https://github.com/nullyks/Arduino_UNO_R4_server).

## Part 2 - Select a route (4 minutes)

Complete one or two relevant rows. A team may combine categories later; first state the user need each option supports. For the web-server route, identify whether the team has access to an UNO R4 WiFi before choosing it.

| Project interaction or feedback | Category and candidate | Why this helps the user or the test | Hardware, library, power, or other open question |
|---|---|---|---|
|  |  |  |  |
|  |  |  |  |

If your project requires movement, record the motor load, driver, and power source. Inspect an instructor-prepared setup or diagram; only wire a motor when the correct parts are available and an instructor has checked the circuit. If selecting a display or LED element, note how the intended user will read or perceive it in the real context. If selecting a web interface, note the phone or computer the user will use and how it joins the board's network.

## Output

One or two candidate routes from sensing, screens or LED elements, movement, and a browser interface; a reason tied to the project interaction; and the unknowns to resolve before committing to the Hi-Fi build.

[Next activity →](06-hifi-slice-and-handover.md)

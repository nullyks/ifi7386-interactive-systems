# Read the examples one step at a time

[Session 4](README.md)

Comments and teaching pages are in English, matching the course. Comments explain WHY a step exists and what each new programming idea means. You do not have to type the complete program from memory.

## Which file do I open?

| Stage | Group 1 | Group 2 | What should happen? |
|---|---|---|---|
| 1, no Pi/Wi-Fi | `examples/library_serial/library_serial.ino` | `examples/ticket_serial/ticket_serial.ino` | Real sensor readings or UIDs in Serial Monitor |
| 2, transmission | `examples/library/library.ino` | `examples/ticket/ticket.ino` | Same physical input, plus JSON and HTTP reply |
| 3, display | `examples/host/server.js`, then `index.html` | Same host; also `tickets.json` | Map responds to physical input |

Open the .ino file in its same-named folder, choose UNO R4 WiFi and the USB port, upload, then open Serial Monitor at 115200. Keep each serial-only program as a known working reference. Stage 2 repeats its sensor functions so you can compare them directly. G1 must COPY its measured four threshold values into the second sketch. Stage 2 is a separate sketch, not a file pasted after Stage 1.

## Arduino ideas used in Stage 1

- `//` starts a comment: it explains a line but does not run.
- A variable is a named place for a value. `int` holds a whole number; `bool` holds true/false; `String` holds text.
- `const` means a setting should stay unchanged while the program runs. Edit its value in the source and upload again to change it.
- `=` assigns a value; `==` compares two values; `!=` means different.
- `if` runs its block only when a condition is true. Braces `{ }` group the steps.
- A function names reusable steps. `readChairs()` calls that function. `return` ends a function and can return a result.
- `setup()` runs once on startup; `loop()` repeats. `Serial.print()` writes to the monitor; `println()` also starts a new line.
- `delay(100)` pauses for 100 milliseconds. `millis()` reports elapsed time since startup, so we can schedule two tasks at different intervals.
- A list/array stores several items. Indices start at 0. The RFID UID is a list of bytes, converted to text one byte at a time.

Read Stage 1 in this order: pin/settings declarations → setup → loop → the function loop calls. Predict the next monitor output, change one setting, upload, and compare prediction with result. G1: explain raw versus occupied. G2: explain why byte 4 prints as 04 rather than 4.

## What Stage 2 adds

`connectToWifi()` joins the Pi network. `sendToPi()` sends text to a server path and checks the response. Treat these as provided helper functions at first; read their comments when your own data reaches the host. G1 builds a complete seat snapshot every two seconds. G2 sends new UID events plus regular reader heartbeats. Both print outgoing JSON so you can compare it to the data contract.

Do not confuse three successes: a local reading proves sensing; HTTP 200 proves host acceptance; the correct changed browser element proves integration.

## Pi and browser code

`server.js` runs on Pi with Node. Start reading at `handleRequest`: GET / asks for HTML; GET /api/state asks for current state; POST routes accept Arduino data. `JSON.parse` turns text into named data; `JSON.stringify` turns it back into text. Validation checks data before saving it. `snapshot` marks old measurements unknown. Leave validation in place when making changes.

`index.html` runs in the browser. HTML describes content, CSS colours/styles it, SVG draws the plan, and JavaScript changes it. Read `refresh()` first: request state → show library → show ticket → wait and repeat. `async`/`await` let a function wait for a network reply. `try`/`catch` handles failure. `document.getElementById` finds an element by its HTML id; `textContent` changes its text; `setAttribute` changes drawing properties.

Start modifications with ONE setting or label. Suggested entry points: four FSR thresholds, UID keys in tickets.json, written route text, or one chair rectangle position. Keep the validation/network helper code as supplied until the main loop works. The optional simulator and automated test file are support tools, not required code-writing tasks in this 135-minute class.

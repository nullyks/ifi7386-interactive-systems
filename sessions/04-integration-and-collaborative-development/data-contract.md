# Data contract, states and errors

[Session 4](README.md)

Each group runs its OWN server. Group 1 implements /api/seats; Group 2 implements /api/ticket and /api/reader. Both independently implement GET / and GET /api/state. A route belonging to the other group returns HTTP 404.

Firmware sends HTTP POST with Content-Type application/json to Pi 10.42.0.1:3000. Browser polls GET /api/state every second. Version v is number 1. Host stores state in memory. This small example assumes a trusted isolated classroom network; there is no authentication or encrypted transport.

## Requests

POST /api/seats every two seconds, even unchanged:

```json
{"v":1,"seats":[{"id":"L1","occupied":true,"raw":700},{"id":"L2","occupied":false,"raw":80}]}
```

Boolean occupied; integer raw 0–1023; id L1 or L2. One or two unique seats allowed. Complete message validated before update. Partial updates permit a later one-board-per-chair variant. Firmware owns seat IDs; host does not infer location from IP.

POST /api/ticket per new scan, with limited retry:

```json
{"v":1,"uid":"04A1B2C3"}
```

Uppercase hexadecimal UID, no separators, 4/7/10 bytes (8/14/20 characters). Host owns UID-to-seat/route mapping. A well-formed unknown UID is accepted with HTTP 200 and produces unknown-ticket feedback.

POST /api/reader every two seconds:

```json
{"v":1,"ready":true}
```

ready=false reports detected initialization failure and clears old ticket. No scans is normal; no device heartbeat eventually means unknown connectivity.

Success: HTTP 200, `{"ok":true}` confirms receipt, not that a person saw feedback. Group 1 GET /api/state provides only seats with state/raw/seen. Group 2 GET /api/state provides only reader with online/ready/seen and latest ticket with known/seat/route/at. Host receipt timestamps are Unix milliseconds; Arduino needs no synchronized clock. Ticket is null when expired. Do not post response objects as requests.

| Condition | Display / state |
|---|---|
| No seat report or older than 10 s | unknown; grey plus text |
| Fresh occupied=true / false | occupied red / free green, plus labels |
| No active ticket | Scan a ticket |
| Known ticket and online ready reader | Seat highlight, route and text |
| Unknown ticket | Helpful message; no old route |
| Ticket older than 15 s | Clear to scan prompt |
| Reader silence >10 s | Offline/unknown; hide route |
| Detected reader initialization error | Hardware error; clear route |
| Browser cannot reach host | Host unavailable; seats unknown; guidance cleared |

| Response | Meaning / action |
|---|---|
| 400 BAD_JSON | Invalid JSON; inspect punctuation |
| 400 BAD_VERSION | Missing/unsupported v |
| 400 BAD_SEATS / BAD_UID / BAD_READER | Invalid field, type, range or ID |
| 404 NOT_FOUND | Incorrect path or method |
| 413 BODY_TOO_LARGE | Body exceeds 2048 characters; use defined small payload |
| No response | Network/host unavailable; inspect Wi-Fi, retry |

Discuss: why snapshots for occupancy and events for scans? What can be lost or duplicated? Which errors are directly detected and which inferred from silence? Which decisions belong on each layer?

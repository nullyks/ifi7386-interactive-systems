// RUN ON THE PI: node server.js. Stop with Ctrl+C.
// require loads libraries. These three are built into Node.js.
const http = require('node:http');
const fs = require('node:fs');
const path = require('node:path');

const STALE_MS = Number(process.env.STALE_MS || 10000);
// null means no measurement yet. Each seat remembers its own latest reading.
const seats = {
  L1: { occupied: null, raw: null, seen: 0 },
  L2: { occupied: null, raw: null, seen: 0 }
};

function seatState(seat, now) {
  let state = 'unknown';
  if (seat.seen > 0 && now - seat.seen <= STALE_MS) {
    if (seat.occupied) {
      state = 'occupied';
    } else {
      state = 'free';
    }
  }
  return { occupied: seat.occupied, raw: seat.raw, seen: seat.seen, state: state };
}

function snapshot() {
  const now = Date.now();
  return {
    seats: { L1: seatState(seats.L1, now), L2: seatState(seats.L2, now) }
  };
}

function reply(response, status, data) {
  // 200 = success; 400 = invalid data; 404 = unknown path.
  response.writeHead(status, {
    'Content-Type': 'application/json',
    'Cache-Control': 'no-store' // Do not reuse old data from browser cache.
  });
  response.end(JSON.stringify(data)); // Convert data back to JSON text.
}

function validSeats(data) {
  // Check the WHOLE message before changing stored data.
  if (!Array.isArray(data.seats)) {
    return false;
  }
  if (data.seats.length < 1 || data.seats.length > 2) {
    return false;
  }
  const usedIds = [];
  for (const seat of data.seats) {
    if (seat === null || typeof seat !== 'object') {
      return false;
    }
    if (seat.id !== 'L1' && seat.id !== 'L2') {
      return false;
    }
    if (usedIds.includes(seat.id)) {
      return false;
    } // No duplicate seat IDs.
    usedIds.push(seat.id);
    // true is boolean; 'true' is text and is NOT accepted.
    if (typeof seat.occupied !== 'boolean') {
      return false;
    }
    if (!Number.isInteger(seat.raw) || seat.raw < 0 || seat.raw > 1023) {
      return false;
    }
  }
  return true;
}

// async/await allows waiting for network input without blocking Node.
async function handleRequest(request, response) {
  const endpoint = new URL(request.url, 'http://localhost').pathname;
  // GET asks for information. These two routes serve the browser.
  if (request.method === 'GET' && endpoint === '/') {
    response.writeHead(200, { 'Content-Type': 'text/html; charset=utf-8', 'Cache-Control': 'no-store' });
    response.end(fs.readFileSync(path.join(__dirname, 'index.html')));
    return; // This request is finished.
  }
  if (request.method === 'GET' && endpoint === '/api/state') {
    reply(response, 200, snapshot());
    return;
  }
  // POST brings new data from Arduino.
  const known = ['/api/seats'];
  if (request.method !== 'POST' || !known.includes(endpoint)) {
    reply(response, 404, { error: 'NOT_FOUND' });
    return;
  }
  try {
    let body = '';
    // A message may arrive in pieces: join them before reading JSON.
    for await (const chunk of request) {
      body += chunk;
      if (body.length > 2048) {
        reply(response, 413, { error: 'BODY_TOO_LARGE' });
        return;
      }
    }
    let data;
    try {
      data = JSON.parse(body);
    } catch (error) {
      reply(response, 400, { error: 'BAD_JSON' });
      return;
    }
    if (!data || data.v !== 1) {
      reply(response, 400, { error: 'BAD_VERSION' });
      return;
    }
    if (endpoint === '/api/seats') {
      if (!validSeats(data)) {
        reply(response, 400, { error: 'BAD_SEATS' });
        return;
      }
      for (const seat of data.seats) {
        seats[seat.id] = { occupied: seat.occupied, raw: seat.raw, seen: Date.now() };
      }
    }
    reply(response, 200, { ok: true });
  } catch (error) {
    if (!response.headersSent) {
      reply(response, 400, { error: 'REQUEST_FAILED' });
    }
  }
}

function createServer() {
  return http.createServer(handleRequest);
}
// Direct run starts server; tests can import it without starting it.
if (require.main === module) {
  const port = Number(process.env.PORT || 3000);
  const server = createServer();
  // 0.0.0.0 accepts connections from other devices too.
  server.listen(port, '0.0.0.0', function () {
    console.log('Open http://10.42.0.1:' + port);
    console.log('Local test: http://localhost:' + port);
  });
}
module.exports = { createServer: createServer };

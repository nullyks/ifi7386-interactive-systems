// SUPPORT FILE for the instructor. Run: node --test test.js.
// These automated checks send requests to a temporary local server.
const { test } = require('node:test');
const assert = require('node:assert/strict');
// Shorten expiry ONLY inside this test so it does not take ten seconds.
process.env.STALE_MS = '150';
const { createServer } = require('./server');

test('HTTP integration: readings, invalid data, tickets and expiry', async function () {
  const server = createServer();
  // Port 0 asks the operating system to choose an unused test port.
  await new Promise(function (done) {
    server.listen(0, '127.0.0.1', done);
  });
  const address = 'http://127.0.0.1:' + server.address().port;

  async function post(endpoint, data) {
    let body = data;
    if (typeof data !== 'string') {
      body = JSON.stringify(data);
    }
    return fetch(address + endpoint, {
      method: 'POST',
      headers: { 'Content-Type': 'application/json' },
      body: body
    });
  }
  async function getState() {
    const response = await fetch(address + '/api/state');
    return response.json();
  }

  try {
    let state = await getState();
    assert.equal(state.seats.L1.state, 'unknown');
    let response = await post('/api/seats', {
      v: 1, seats: [{ id: 'L1', occupied: true, raw: 700 }]
    });
    assert.equal(response.status, 200);
    state = await getState();
    assert.equal(state.seats.L1.state, 'occupied');

    await post('/api/seats', {
      v: 1, seats: [{ id: 'L2', occupied: false, raw: 80 }]
    });
    state = await getState();
    assert.equal(state.seats.L2.state, 'free');

    // Each invalid request must be rejected with HTTP 400.
    const invalidMessages = [
      '{', null, { v: 2 },
      { v: 1, seats: [{ id: '__proto__', occupied: true, raw: 1 }] },
      { v: 1, seats: [{ id: 'L1', occupied: 'yes', raw: 1 }] },
      { v: 1, seats: [{ id: 'L1', occupied: true, raw: 1024 }] },
      { v: 1, seats: [
        { id: 'L1', occupied: true, raw: 700 },
        { id: 'L1', occupied: false, raw: 80 }
      ] }
    ];
    for (const message of invalidMessages) {
      response = await post('/api/seats', message);
      assert.equal(response.status, 400);
    }
    // A valid first item + invalid second item must NOT partly update L1.
    response = await post('/api/seats', {
      v: 1, seats: [
        { id: 'L1', occupied: false, raw: 10 },
        { id: 'wrong', occupied: false, raw: 20 }
      ]
    });
    assert.equal(response.status, 400);
    state = await getState();
    assert.equal(state.seats.L1.raw, 700);

    response = await post('/api/ticket', { v: 1, uid: '04A1B2C3' });
    assert.equal(response.status, 200);
    state = await getState();
    assert.equal(state.ticket.seat, 'A2');
    await post('/api/ticket', { v: 1, uid: 'FFFFFFFF' });
    state = await getState();
    assert.equal(state.ticket.known, false);
    response = await post('/api/ticket', { v: 1, uid: 'wrong' });
    assert.equal(response.status, 400);

    await post('/api/reader', { v: 1, ready: false });
    state = await getState();
    assert.equal(state.ticket, null);
    assert.equal(state.reader.ready, false);
    // Wait long enough for our shortened test expiry.
    await new Promise(function (done) { setTimeout(done, 180); });
    state = await getState();
    assert.equal(state.seats.L1.state, 'unknown');
    assert.equal(state.reader.online, false);
    response = await fetch(address + '/');
    assert.equal(response.status, 200);
    response = await fetch(address + '/missing');
    assert.equal(response.status, 404);
  } finally {
    // Always release the test server, even when a check fails.
    await new Promise(function (done) { server.close(done); });
  }
});

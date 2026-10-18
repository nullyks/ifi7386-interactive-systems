// SUPPORT FILE for the instructor. Run: node --test test.js.
// These automated checks send requests to a temporary local server.
const { test } = require('node:test');
const assert = require('node:assert/strict');
// Shorten expiry ONLY inside this test so it does not take ten seconds.
process.env.STALE_MS = '150';
process.env.TICKET_MS = '150';
const { createServer } = require('./server');

test('HTTP integration: Group 2 tickets, validation, isolation and expiry', async function () {
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
    assert.equal(state.reader.online, false);
    assert.equal(state.ticket, null);
    assert.equal(state.seats, undefined);
    let response;
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
    // Group 2 rejects Group 1 endpoints and also validates reader heartbeats.
    response = await post('/api/seats', { v: 1, seats: [] });
    assert.equal(response.status, 404);
    response = await post('/api/reader', { v: 1, ready: 'true' });
    assert.equal(response.status, 400);
    response = await post('/api/ticket', '{');
    assert.equal(response.status, 400);
    response = await post('/api/ticket', { v: 2, uid: '04A1B2C3' });
    assert.equal(response.status, 400);
    await post('/api/ticket', { v: 1, uid: '04112233' });
    state = await getState();
    assert.equal(state.ticket.seat, 'B3');
    await new Promise(function (done) { setTimeout(done, 180); });
    state = await getState();
    assert.equal(state.reader.online, false);
    assert.equal(state.ticket, null);
    response = await fetch(address + '/');
    assert.equal(response.status, 200);
    response = await fetch(address + '/missing');
    assert.equal(response.status, 404);
  } finally {
    // Always release the test server, even when a check fails.
    await new Promise(function (done) { server.close(done); });
  }
});

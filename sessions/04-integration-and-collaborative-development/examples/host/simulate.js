// OPTIONAL host troubleshooting after real sensor readings work.
// Run: node simulate.js library | ticket UID | reader-error
const host = process.env.HOST_URL || 'http://localhost:3000';
const mode = process.argv[2]; // The word after node simulate.js.

async function send(endpoint, message) {
  message.v = 1;
  try {
    const response = await fetch(host + endpoint, {
      method: 'POST',
      headers: { 'Content-Type': 'application/json' },
      body: JSON.stringify(message)
    });
    console.log(response.status, await response.text());
    if (!response.ok) {
      process.exitCode = 1;
    }
  } catch (error) {
    console.log('Cannot reach host. Start server.js and check address.');
    process.exitCode = 1;
  }
}

let occupied = false;
function sendChairs() {
  let reading = 100;
  if (occupied) {
    reading = 700;
  }
  send('/api/seats', {
    seats: [
      { id: 'L1', occupied: occupied, raw: reading },
      { id: 'L2', occupied: false, raw: 80 }
    ]
  });
  occupied = !occupied; // Swap true and false for the next message.
}

if (mode === 'library') {
  sendChairs();
  setInterval(sendChairs, 2000); // Repeat every two seconds until Ctrl+C.
} else if (mode === 'ticket') {
  const uid = process.argv[3] || '04A1B2C3';
  send('/api/ticket', { uid: uid });
} else if (mode === 'reader-error') {
  send('/api/reader', { ready: false });
} else {
  console.log('Usage: node simulate.js library | ticket UID | reader-error');
}

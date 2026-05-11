const http = require('http');

console.log('BLOCKING Server started!');

const server = http.createServer((req, res) => {
    const startTime = new Date();
    console.log(`[${startTime.toISOString()}] receive request: ${req.url}`);

    if (req.url === '/fast') {
        // fast response
        res.writeHead(200, { 'Content-type': 'text/plain' });
        res.end(`fast response! (${new Date() - startTime}ms)\n`);
        console.log(`[${new Date().toISOString()}] end FAST response`);
    }
    else if (req.url === '/slow') {
        // slowly response
        console.log(`[${new Date().toISOString()}] start slow response`);

        const blockStart = Date.now();
        while (Date.now() - blockStart < 10000) {

        }

        res.writeHead(200, { 'content-type': 'text/plain' });
        res.end(`slow response! (${new Date() - startTime}ms)\n`);
        console.log(`[${new Date().toISOString()}] end SLOW response`)
    }
    else {
        res.writeHead(200, { 'Content-type': 'text/html' });
        res.end(`
            <h1>BLOCKING Server</h1>
            <p>This server don't work while response /slow is working</p>
            <ul>
                <li><a href="/fast">/fast</a> - fast response</li>
                <li><a href="/slow">/slow</a> - 10s block working</li>
            </ul>
            <p>method testing</p>
            <ol>
                <li>click /slow at this page</li>
                <li>just at new tab connect /fast</li>
                <li>second response 10s waiting</li>
            </ol>
        `);
    }
});

server.listen(3001, () => {
    console.log('BLOCKING Server is open: http://localhost:3001');
    console.log('If you want testing:');
    console.log('1. Terminal1: curl http://localhost:3001/slow');
    console.log('2. just terminal2: curl http://localhost:3001/fast');
    console.log('==============================================\n');
});
const http = require('http');

console.log('Non-blocking Server Started!');

const server = http.createServer((req, res) => {
    const startTime = new Date();
    console.log(`[${startTime.toISOString()}] Received request: ${req.url}`);

    if (req.url === '/fast') {
        res.writeHead(200, { 'Content-Type': 'text/plain' });
        res.end(`Fast response (${new Date() - startTime}ms)\n`);
        console.log(`[${new Date().toISOString()}] Completed FAST response`);
    }
    else if (req.url === '/slow') {
        console.log(`[${new Date().toISOString()}] Starting slow response (non-blocking)`);

        setTimeout(() => {
            res.writeHead(200, { 'Content-Type': 'text/plain' });
            res.end(`Slow response (${new Date() - startTime}ms)\n`);
            console.log(`[${new Date().toISOString()}] Completed SLOW response`);
        }, 10000);
    }
    else if (req.url === '/io-slow') {
        console.log(`[${new Date().toISOString()}] Starting file I/O simulation`);

        const simulateFileRead = (callback) => {
            setTimeout(() => {
                callback(null, 'File content: Hello from non-blocking I/O');
            }, 5000);
        };

        simulateFileRead((err, data) => {
            if (err) {
                res.writeHead(500, { 'Content-Type': 'text/plain' });
                res.end('Error reading file\n');
            } else {
                res.writeHead(200, { 'Content-Type': 'text/plain' });
                res.end(`${data} (total time: ${new Date() - startTime}ms)\n`);
                console.log(`[${new Date().toISOString()}] Completed file I/O response`);
            }
        });
    }
    else if (req.url === '/parallel') {
        console.log(`[${new Date().toISOString()}] Starting parallel requests`);

        const results = [];
        const tasks = [1000, 2000, 3000];

        let completed = 0;

        const checkAllCompleted = () => {
            if (completed === tasks.length) {
                res.writeHead(200, { 'Content-Type': 'application/json' });
                res.end(JSON.stringify({
                    message: 'All parallel tasks completed!',
                    result: results,
                    totalTime: `${new Date() - startTime}ms`
                }, null, 2)); // 3rd parameter: 2 spaces indentation for pretty JSON
                console.log(`[${new Date().toISOString()}] All parallel tasks done`);
            }
        };

        tasks.forEach((delay, index) => {
            setTimeout(() => {
                results[index] = `Task ${index + 1} done in ${delay}ms`;
                completed++;
                console.log(`[${new Date().toISOString()}] Task ${index + 1} completed`);

                checkAllCompleted();
            }, delay);
        });
    }
    else {
        res.writeHead(200, { 'Content-Type': 'text/html' });
        res.end(`
            <!DOCTYPE html>
            <html lang="en">
            <head>
                <title>Non-Blocking Server Demo</title>
                <meta charset="UTF-8">
                <style>
                    body { font-family: Arial, sans-serif; margin: 40px; }
                    .demo { background: #f0f0f0; padding: 20px; margin: 20px 0; border-radius: 5px; }
                    .blocking { background: #ffe6e6; }
                    .non-blocking { background: #e6ffe6; }
                    a { display: inline-block; margin: 5px; padding: 10px 15px; background: #007bff; color: white; text-decoration: none; border-radius: 3px; }
                    a:hover { background: #0056b3; }
                    code { background: #333; color: #fff; padding: 2px 5px; border-radius: 3px; }
                </style>
            </head>
            <body>
                <h1>NON-BLOCKING Server Demo</h1>
                
                <div class="demo">
                    <h2>📊 Comparison</h2>
                    <div class="blocking">
                        <h3>Blocking Server (Port 3001)</h3>
                        <p>Concurrent requests are NOT possible. /fast must wait while /slow is processing.</p>
                        <a href="http://localhost:3001" target="_blank">Test Blocking Server</a>
                    </div>
                    <div class="non-blocking">
                        <h3>Non-Blocking Server (Port 3002 - This server)</h3>
                        <p>Concurrent requests ARE possible! /fast responds immediately even while /slow is processing.</p>
                        <p>Reason: setTimeout registers work in the callback queue and returns immediately.</p>
                    </div>
                </div>
                
                <div class="demo">
                    <h2>🔄 Test Endpoints</h2>
                    <p><strong>Open these links in separate tabs simultaneously to test!</strong></p>
                    
                    <h3>1. Basic Tests</h3>
                    <a href="/fast" target="_blank">/fast - Immediate Response</a>
                    <a href="/slow" target="_blank">/slow - 10-second Response (Non-blocking)</a>
                    
                    <h3>2. I/O Operation Simulation</h3>
                    <a href="/io-slow" target="_blank">/io-slow - Simulated File Read (5 seconds)</a>
                    
                    <h3>3. Parallel Tasks</h3>
                    <a href="/parallel" target="_blank">/parallel - Parallel Task Execution</a>
                </div>
                
                <div class="demo">
                    <h2>🎯 Testing Method</h2>
                    <ol>
                        <li>Open two terminal windows</li>
                        <li>Terminal 1: <code>curl http://localhost:3002/slow</code></li>
                        <li>Terminal 2 (after 2 seconds): <code>curl http://localhost:3002/fast</code></li>
                        <li>Result: /fast responds immediately without waiting for /slow!</li>
                    </ol>
                </div>
                
                <div class="demo">
                    <h2>🔍 Node.js Event Loop Behavior</h2>
                    <pre>
1. /slow request arrives
2. setTimeout() called → registered in Timer Queue
3. Function returns immediately (main thread not blocked)
4. Event loop can process other requests (/fast)
5. After 10 seconds, timer queue callback executes
                    </pre>
                </div>
                
                <div class="demo">
                    <h2>📈 Key Concepts Demonstrated</h2>
                    <ul>
                        <li><strong>Non-blocking I/O</strong>: setTimeout schedules work for later</li>
                        <li><strong>Event Loop</strong>: Single thread handles multiple requests</li>
                        <li><strong>Concurrency</strong>: Multiple requests processed seemingly simultaneously</li>
                        <li><strong>Callback Pattern</strong>: Standard Node.js async pattern</li>
                    </ul>
                </div>
            </body>
            </html>
        `);
    }
});

const PORT = 3002;
server.listen(PORT, () => {
    console.log(`NON-BLOCKING Server is running at: http://localhost:${PORT}`);
    console.log('\n=== TESTING INSTRUCTIONS ===');
    console.log('1. Terminal 1: curl http://localhost:3002/slow');
    console.log('2. Wait 2 seconds, then Terminal 2: curl http://localhost:3002/fast');
    console.log('3. Result: /fast responds immediately!');
    console.log('\n=== BROWSER TESTING ===');
    console.log('- Open http://localhost:3002/slow');
    console.log('- Open http://localhost:3002/fast in new tab immediately');
    console.log('- Both tabs work independently');
    console.log('\n=== COMPARE WITH BLOCKING SERVER ===');
    console.log('- Run blocking-server.js on port 3001');
    console.log('- Repeat tests to see the difference');
    console.log('========================================\n');
});
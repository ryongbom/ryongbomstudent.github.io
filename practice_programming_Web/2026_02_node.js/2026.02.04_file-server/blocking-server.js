const http = require('http');
const fs = require('fs');
const path = require('path');

const server = http.createServer((req, res) => {
    console.log(`[${new Date().toISOString()}] Request received`);

    if (req.url === '/file') {
        console.log('Starting file read using blocking method...');

        const filePath = path.join(__dirname, 'large-file.txt');
        const data = fs.readFileSync(filePath); // Blocking I/O

        console.log('File read complete, sending response...');
        res.writeHead(200, { 'Content-Type': 'text/plain; charset=utf-8' });
        res.end(data);

        console.log('Response sent');
    } else {
        res.writeHead(200, { 'Content-Type': 'text/html' });
        res.end(`
            <html>
            <head>
                <meta charset="UTF-8">
            </head>
                <body>
                    <h1>Blocking Server Test</h1>
                    <button onclick="fetchFile()">Request Large File</button>
                    <div id="status"></div>
                    <script>
                        async function fetchFile() {
                            document.getElementById('status').textContent = 'Requesting...';
                            const start = Date.now();
                            await fetch('/file');
                            const time = Date.now() - start;
                            document.getElementById('status').textContent = \`Complete! Took \${time}ms\`;
                        }
                    </script>
                </body>
            </html>
        `);
    }
});

server.listen(3000, () => {
    console.log('Blocking server: http://localhost:3000');
    console.log('※ This server cannot handle concurrent requests!');
});
// const http = require('http');

// http.createServer((req, res) => {
//     res.writeHead(200, { 'Content-Type': 'text/plain' });
//     res.end("Hello");
// }).listen(8081);

// console.log('Server running at http://127.0.0.1:8081/');

const express = require('express');
const app = express();

app.use('/', (req, res) => {
    res.send('Hello');
});

app.listen(3000);

console.log('Server running at http://127.0.0.1:3000/');
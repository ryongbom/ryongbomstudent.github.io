// var http = require("http");
// http.createServer(function (request, response) {

//     response.writeHead(200, { 'content-type': 'text/plain; charset=UTF-8' });
//     response.end('안녕하십니까?');
// }).listen(8081);

// console.log('Server is running at http://127.0.0.1:8081');

// var fs = require("fs");

// var data = fs.readFileSync('input.txt');
// console.log(data.toString());
// console.log("프로그람완료");

var fs = require("fs");

fs.readFile('input.txt', function (err, data) {
    if (err) return console.error(err);
    console.log(data.toString());
});
console.log("프로그람완료");
// const express = require('express');
// const { log } = require('node:console');
// const app = express();

// const logger = (req, res, next) => {
//     console.log(req.method, req.url);

//     next();
// };

// const helloWorld = (req, res, next) => {
//     res.send('Hello World');
// };

// app.use(logger);
// app.use(helloWorld);

// app.listen(3000);
// console.log('Server running at http://localhost:3000/');

const express = require('express');
const bodyParser = require('body-parser');

const app = express();

app.use(bodyParser.urlencoded({ extended: true }));

let logger = (req, res, next) => {
    console.log(req.method, req.url);
    next();
}

let hasName = (req, res, next) => {
    if (req.method == 'GET' && req.query.username) {
        next();
    } else if (req.method == 'POST' && req.body.username) {
        next();
    } else {
        res.send('Input username please!');
    }
}

app.get('/test', [hasName, logger], function (req, res) {
    res.send('username=' + req.query.username);
});

app.post('/test', [hasName, logger], function (req, res) {
    res.send('username=' + req.body.username);
});

app.put('/test/:id', logger, function (req, res) {
    res.send('id=' + req.params.id);
})

app.delete('/test/:id', function (req, res) {
    res.send('id=' + req.params.id);
})

var server = app.listen(3000, function () {
    var host = server.address().address
    var port = server.address().port
    console.log("Example app listening at http://%s:%s", host, port)
})


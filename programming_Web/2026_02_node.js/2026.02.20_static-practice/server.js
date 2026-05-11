const express = require('express');
const app = express();

app.use(express.static('public'));
app.use('/css', express.static('public/css'));

const port = 3000;
app.listen(port, () => console.log('Server running on port %s', port));

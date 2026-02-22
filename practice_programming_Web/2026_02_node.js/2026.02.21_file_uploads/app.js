const express = require('express');
const multer = require('multer');
const path = require('path');
const app = express();

app.set('view engine', 'ejs');
app.use(express.urlencoded({ extended: true }));
app.use(express.json());
app.use('/uploads', express.static('uploads'));

const PORT = 3000;
app.listen(PORT, () => {
    console.log(`Server is running at http://localhost:${PORT}`);
});

const upload = multer({ storage: storage });

app.get('/', (req, res) => {
    res.render('index');
})

app.post('/upload', upload.single('myFile'), (req, res) => {
    res.send(`
        <h2>Successfully uploaded!</h2>
        <p>file name: ${req.file.originalname}</p>
        <p>description: ${req.body.description}</p>
        <a href="/">back</a>
    `)

    console.log('Information:', req.file);
});

const storage = multer.diskStorage({
    destination: (req, res, cb) => {
        cb(null, 'uploads/');
    },

    filename: (req, res, cb) => {
        cb(null, Date.now() + '-' + file.originalname);
    }
})

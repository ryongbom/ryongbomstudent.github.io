const express = require('express');
const mongoose = require('mongoose');
const multer = require('multer');
const path = require('path');
const bcrypt = require('bcryptjs');
const User = require('./models/User');
const app = express();

app.use(express.json());
app.use(express.urlencoded({ extended: true }));
app.set('view engine', 'ejs');
app.use('/uploads', express.static('uploads'));

mongoose.connect('mongodb://localhost:27017/userapp')
    .then(() => {
        console.log('successfully connected to mongoDB!');
        app.listen(3000, () => {
            console.log('Server is running at http://localhost:3000');
        });
    })
    .catch(err => {
        console.log('Connecting error!', err);
    });

const storage = multer.diskStorage({
    destination: (req, file, cb) => {
        cb(null, 'uploads/');
    },
    filename: (req, file, cb) => {
        const uniqueSuffix = Date.now() + '-' + Math.round(Math.random() * 1E9);
        const ext = path.extname(file.originalname);
        cb(null, uniqueSuffix + ext);
    }
});

const upload = multer({ storage: storage });

app.get('/', (req, res) => {
    res.send('User Register practice');
});

app.get('/register', (req, res) => {
    res.render('register');
});

app.post('/register', upload.single('profileImage'), async (req, res) => {
    try {
        let profileImage = 'default.png';
        if (req.file) {
            profileImage = req.file.filename;
        }

        // It is very important for password
        const salt = await bcrypt.genSalt(10);
        const hashedPassword = await bcrypt.hash(req.body.password, salt);

        const newUser = new User({
            name: req.body.name,
            mail: req.body.email,
            profileImage,
            password: hashedPassword
        });

        await newUser.save();

        res.send(`
            <h2>✅ 회원가입 성공!</h2>
            <p>이름: ${newUser.name}</p>
            <p>이메일: ${newUser.mail}</p>
            <p>프로필: ${newUser.profileImage}</p>
            <a href="/register">돌아가기</a>
        `);
    }
    catch (err) {
        console.error(err);

        if (err.code === 11000) {
            return res.send('<h2>❌ 이미 존재하는 이메일입니다.</h2><a href="/register">돌아가기</a>');
        }

        res.send('<h2>❌ 회원가입 실패!</h2><a href="/register">돌아가기</a>');
    }
});


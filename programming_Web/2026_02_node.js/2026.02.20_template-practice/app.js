const express = require('express');
const app = express();
const PORT = 3000;

app.set('view engine', 'ejs');
app.set('views', './views');

// 기존 홈페이지
app.get('/', (req, res) => {
    res.render('index', {
        name: 'Kim Chol Su',
        message: 'Template study'
    });
});

// 🆕 프로필 페이지 추가
app.get('/profile', (req, res) => {
    // 사용자 데이터 (실제로는 DB에서 가져옴)
    const userData = {
        name: '박영희',
        job: '디자이너',
        age: 28,
        hobbies: ['그림그리기', '요가', '여행'],
        isOnline: true
    };

    res.render('profile', {
        title: `${userData.name}님의 프로필`,
        user: userData
    });
});

// 🆕 다른 사용자 프로필 (URL 파라미터 사용)
app.get('/profile/:username', (req, res) => {
    const username = req.params.username;

    // 사용자 이름에 따라 다른 데이터 (예시)
    const users = {
        'kim': {
            name: '김철수',
            job: '개발자',
            age: 25,
            hobbies: ['코딩', '영화', '게임'],
            isOnline: false
        },
        'park': {
            name: '박영희',
            job: '디자이너',
            age: 28,
            hobbies: ['그림', '요가', '여행'],
            isOnline: true
        },
        'lee': {
            name: '리민수',
            job: 'PM',
            age: 32,
            hobbies: ['독서', '축구', '음악감상'],
            isOnline: true
        }
    };

    const user = users[username] || users['kim']; // 기본값: kim

    res.render('profile', {
        title: `${user.name}님의 프로필`,
        user: user
    });
});

app.listen(PORT, () => {
    console.log(`Server is running: http://localhost:${PORT}`);
    console.log(`👉 http://localhost:${PORT}/profile`);
    console.log(`👉 http://localhost:${PORT}/profile/kim`);
    console.log(`👉 http://localhost:${PORT}/profile/park`);
    console.log(`👉 http://localhost:${PORT}/profile/lee`);
});
const express = require('express');
const app = express();

// JSON data settings
app.use(express.json());
app.use(express.urlencoded({ extended: true }));

// === GET routing pracice ===
// 1. main GET
app.get('/', (req, res) => {
    res.send('Welcome to homepage!');
});

// 2. GET with URL parameter
app.get('/user/:id', (req, res) => {
    res.send(`user ${req.params.id}'s profile`);
});

// 3. GET with query parameter
app.get('/search', (req, res) => {
    const query = req.query.q || 'not result';
    res.send(`result searching: ${query}`);
});

// === POST routing practice ===
app.post('/login', (req, res) => {
    res.send('logging...');
});

app.post('/register', (req, res) => {
    res.send('working logging...');
});

// === PUT routing practice ===
app.put('/user/:id', (req, res) => {
    res.send(`user ${req.params.id}'s information changed!`);
});

// === DELETE routing practice ===
app.delete('/user/:id', (req, res) => {
    res.send(`user ${req.params.id}'s profile is deleted!`);
});

// === req.params practice ===
app.get('/product/:category/:id', (req, res) => {
    const { category, id } = req.params;
    res.json(
        {
            type: 'URL parameter example',
            category: category,
            productId: id,
            message: `${category} 's ${id} product`
        }
    );
});

app.get('/blog/:year/:month/:slug', (req, res) => {
    const { year, month, slug } = req.params;
    res.json({
        type: 'URL parameter example',
        url: `/${year}/${month}/${slug}`,
        date: `${year} year ${month} month`,
        title: `${slug} text`
    });
});

// === req.query practice ===
app.get('/products', (req, res) => {
    const { category, minPrice, maxPrice, sort } = req.query;

    res.json({
        type: '쿼리 파라미터 예제',
        receivedParams: req.query,
        message: `${category || '모든'} 상품을 ` +
            `${minPrice || 0}원~${maxPrice || '최대'}원 범위에서 ` +
            `${sort || '기본'} 정렬로 검색합니다`
    });
});

const PORT = 3000;
app.listen(PORT, () => {
    console.log(`   서버가 http://localhost:${PORT} 에서 실행 중`);
});
const express = require('express');
const app = express();

app.listen(3000, () => {
    console.log('Server is running at server http://localhost:3000');
});

let foods = [
    { id: 1, name: '김치', category: '조선음식' },
    { id: 2, name: '랭면', category: '조선음식' },
    { id: 3, name: '즉석국수', category: '조선음식' },
    { id: 4, name: '카틀레트', category: '유럽식' },
    { id: 5, name: '똘트', category: '유럽식' },
    { id: 6, name: '스빠께띠', category: '유럽식' },
    { id: 7, name: '우동', category: '중국식' },
    { id: 8, name: '교즈', category: '중국식' },
    { id: 9, name: '만투', category: '중국식' },
    { id: 10, name: '햄버거', category: '유럽식' }
];

app.get('/api/foods', (req, res) => {
    res.json(foods);
});

app.get('/api/random', (req, res) => {
    const size = foods.length;
    const randomIndex = Math.floor(Math.random() * size);
    const food = foods[randomIndex];

    res.json(food);
});

app.get('/api/category/:type', (req, res) => {
    const type = req.params.type;
    const filteredFood = foods.filter(f => f.category === type);

    if (filteredFood.length === 0) {
        res.status(404).json({ error: '없는 카테고리' });
    }
    res.json(filteredFood);
});

app.get('/', (req, res) => {
    const index = Math.floor(Math.random() * foods.length);
    const food = foods[index];

    res.render('index', { food: food });
})

app.set('view engine', 'ejs');
app.set('views', './views');
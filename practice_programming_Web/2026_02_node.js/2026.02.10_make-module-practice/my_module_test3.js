const Currency1 = require('./my_module3');
currency1 = new Currency1();
console.log('첫 객체의 초기환룔값 = ' + currency1.rate);

currency1.rate = 90;

const Currency2 = require('./my_module3');
currency2 = new Currency2();
console.log("두번째 객체의 초기환률값 = " + currency2.rate);
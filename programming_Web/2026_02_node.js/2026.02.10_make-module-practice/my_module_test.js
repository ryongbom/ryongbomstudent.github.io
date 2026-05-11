const currency = require('./my_module.js');

console.log('이전 시세 = ' + currency.rate);
currency.rate = 110;
console.log('현재 시세 = ' + currency.rate);

console.log('20 외화원 = ' + currency.foreignToWon(20) + '원');
console.log('20000 원 = ' + currency.wonToForeign(20000) + '외화원');
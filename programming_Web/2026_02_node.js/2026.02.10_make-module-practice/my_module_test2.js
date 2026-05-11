const Currency = require('./my_module2');

currency = new Currency(100);
console.log('20 외화원 = ' + currency.foreignToWon(20) + '원');

currency.rate = 110;
console.log('20 외화원 = ' + currency.foreignToWon(20) + '원');
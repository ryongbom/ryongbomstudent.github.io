let rate = 100;

class Currency {
    get rate() {
        return rate;
    }

    set rate(val) {
        rate = val;
    }
}

module.exports = Currency;
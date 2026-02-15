class Currency {
    constructor(rate) {
        this._rate = rate;
    }

    get rate() {
        return this._rate;
    }

    set rate(rate) {
        this._rate = rate;
    }

    roundTwoDecimals = amount => {
        return Math.round(amount * 100) / 100;
    }

    foreignToWon = foreign => {
        return this.roundTwoDecimals(foreign * this._rate);
    }

    wonToForeign = won => {
        return this.roundTwoDecimals(won / this._rate);
    }
}

module.exports = Currency;
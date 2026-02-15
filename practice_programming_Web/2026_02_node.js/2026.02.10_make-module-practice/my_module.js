let rate = 100;

roundTwoDecimals = amount => {
    return Math.round(amount * 100) / 100;
}

exports.rate = rate;

exports.foreignToWon = foreign => {
    return roundTwoDecimals(foreign * rate);
}

exports.wonToForeign = won => {
    return roundTwoDecimals(won / rate);
}
function delay(ms) {
    return new Promise(resolve => setTimeout(resolve, ms));
}

async function countDown() {
    console.log("3...");
    await delay(1000);
    console.log("2...");
    await delay(1000);
    console.log("1...");
    await delay(1000);
    console.log("Start!");
}

countDown();
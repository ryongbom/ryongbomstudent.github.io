// // write data to Buffer
// var buf = new Buffer.alloc(256);
// var len = buf.write("Hello World?");

// console.log("byte: " + len);

// var buf = new Buffer.alloc(26);
// for (let i = 0; i < 26; i++) {
//     buf[i] = i + 97;
// }

// // load data from Buffer
// console.log(buf.toString('ascii'));
// console.log(buf.toString('ascii', 0, 5));
// console.log(buf.toString('utf-8', 0, 5));
// console.log(buf.toString(undefined, 0, 5));

// // connect 2 Buffers
// var buffer1 = new Buffer.from('Hello');
// var buffer2 = new Buffer.from('World');

// var buffer3 = Buffer.concat([buffer1, buffer2]);

// console.log("buffer3: " + buffer3.toString());

// // compare 2 Buffers
// var buffer1 = new Buffer.from('ABC');
// var buffer2 = new Buffer.from('ABCD');
// var result = buffer1.compare(buffer2);

// if (result < 0) {
//     console.log(buffer1 + " < " + buffer2);
// } else if (result == 0) {
//     console.log(buffer1 + " = " + buffer2);
// } else {
//     console.log(buffer1 + " > " + buffer2);
// }

// // copy buffer
// var buffer1 = new Buffer.from('ABC');
// var buffer2 = new Buffer.alloc(3);

// buffer1.copy(buffer2);

// console.log('buffer2: ' + buffer2.toString());

// // cat buffer
// var buffer1 = new Buffer.from('123456789');

// var buffer2 = buffer1.slice(2, 5);

// console.log('buffer2: ' + buffer2.toString());

// buffer1[3] = 66;
// console.log('buffer2: ' + buffer2.toString());

// // length of buffer
// var buffer = new Buffer.from('abcde');

// console.log('length of buffer: ' + buffer.length);
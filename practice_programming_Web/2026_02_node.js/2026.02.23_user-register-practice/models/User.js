const mongoose = require('mongoose');

const UserSchema = new mongoose.Schema({
    name: {
        type: String,
        required: [true, '이름을 입력하십시오.']
    },
    mail: {
        type: String,
        required: [true, '이메일주소를 입력하십시오.'],
        unique: true,
        match: [/.+\@.+\..+/, '올바른 이메일 형식이 아닙니다.']
    },
    profileImage: {
        type: String,
        default: 'default.png'
    },
    password: {
        type: String,
        required: [true, '비밀번호를 입력해주십시오.']
    },
    createdAt: {
        type: Date,
        default: Date.now
    }
});

module.exports = mongoose.model('User', UserSchema);
const worldArray = [
    { msg: 'Hello world!'},
    { msg: 'Hallo Welt!'},
    { msg: '¡Hola mundo!'},
    { msg: '你好世界！'},
    { msg: 'こんにちは世界！'},
    { msg: '여보세요 세계!'}
];

const randomWorld = worldArray[Math.floor(Math.random() * worldArray.length)];

console.log(randomWorld.msg);

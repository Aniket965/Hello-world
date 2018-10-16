const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('What is your name? ', (answer) => {
  console.log('\x1b[32m%s\x1b[0m', `Hello, ${answer}!`);
  rl.close();
});

const text = ('Hello World').split('');

Promise.all(text.map(char => {
  return createPromise(char)
})).then((res) => {
  console.log(res.join(''));
})


function createPromise(_s) {
  return new Promise((resolve) => {
    setTimeout(() => {
      resolve(_s)
    }, Math.random() * 10);
  });
}

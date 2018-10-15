const promise = new Promise(resolve => {
  resolve('Hello world!');
});

promise.then(response => {
  console.log(response);
});

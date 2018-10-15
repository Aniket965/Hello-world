const AsyncAwaitErrorHandler = require('./index');
// Test 
// Simple divide example  

const asyncDivide = (a, b, time = 0) => {
  return new Promise((success, failure) => {
    setTimeout(() => {
      if (isNaN(a) || isNaN(b)) {
        failure(`Dividend and Divisor should be of number type`);
        return;
      }
      if (b === 0) {
        failure(`Can't divide by 0`);
      } else {
        const res = a / b;
        success(res)
      }
    }, time);
  })
}

const verify = async () => {
  const [err0, sum0] = await AsyncAwaitErrorHandler(asyncDivide());
  console.log(err0);

  const [err1, sum1] = await AsyncAwaitErrorHandler(asyncDivide(2, 3));
  console.log(sum1);

  const [err2, sum2] = await AsyncAwaitErrorHandler(asyncDivide('2E', 3));
  console.log(err2);

  const [err3, sum3] = await AsyncAwaitErrorHandler(asyncDivide(3, 0));
  console.log(err3);

  const [err4, sum4] = await AsyncAwaitErrorHandler(asyncDivide(2, 3, 100));
  console.log(sum1);
}

verify();
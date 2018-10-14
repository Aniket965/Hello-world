/**
 * Converts async function that callback
 * into a promise returning function
 *
 * @param Function callback ((err, result) => {})
 */

function callbackToPromise(asyncFn) {
  return new Promise((resolve, reject) => {
    asyncFn((error, result) => {
      if (error) {
        reject(error);
      } else {
        resolve(result);
      }
    });
  });
}

export default callbackToPromise;

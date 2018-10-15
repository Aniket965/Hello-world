/**
 * curried a funtion
 *
 * @param Function fn
 * @param Number len
 */
function curry(fn, len) {
  len = len || fn.length;
  return function curriedFn(...args) {
    if (args.length >= len) {
      return fn(...args);
    } else {
      return curry(fn.bind(null, ...args));
    }
  };
}
export default pipe;

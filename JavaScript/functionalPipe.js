/**
 * pipes an array of function
 *
 * @param Array<Function> args
 */
function pipe(...fns) {
  return function pipedFn(input) {
    return fns.reduce((output, fn) => fn(output), input);
  };
}
export default pipe;

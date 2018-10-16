/**
 * componses an array of function
 *
 * @param Array<Function> args
 */

function componse(...args) {
  const fns = args.slice().reverse();
  return function componsedFn(input) {
    return fns.reduce((output, fn) => fn(output), input);
  };
}

export default componse;

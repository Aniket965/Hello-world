// Utility to handle await error gracefully.
const AsyncAwaitErrorHandler = async (promise) => {
  let success;
  let failure;
  try {
    success = await promise;
  } catch (e) {
    failure = e;
  }
  return [failure, success];
};

module.exports = AsyncAwaitErrorHandler;
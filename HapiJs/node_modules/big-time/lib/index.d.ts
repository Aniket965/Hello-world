interface BigTime {
  ref: () => this;
  unref: () => this;
};

declare namespace bigTime {
  /**
   * Creates a new BigTime timer object and starts the timer.
   * @param callback {function} function to execute after delay has passed.
   * @param delay {number|Date} number of miliseconds to wait. Alternatively, a date which will be subtracted from Date.now
   * @param args {any[]} additional arguments that will be passed through into callback, just like native setTimeout
   */
  function setTimeout(callback: () => void, delay: number|Date, ...args: any[]): BigTime;
  /**
   * Clears a running BigTime timer.
   * @param timer {BigTime} a BigTime instance to clear
   */
  function clearTimeout(timer:BigTime): void;
};

export = bigTime;

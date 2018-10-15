'use strict';
const TIMEOUT_MAX = 2147483647; // 2^31-1

function start (timer, args) {
  const max = module.exports._TIMEOUT_MAX; // Use the exported value for testing purposes.

  if (timer._delay <= max) {
    timer._timeout = setTimeout(timer._callback, timer._delay, ...args);
  } else {
    const callback = () => {
      timer._delay -= max;
      start(timer, args);
    };

    timer._timeout = setTimeout(callback, max, ...args);
  }

  if (timer._ref === false) {
    timer._timeout.unref();
  }
}

class Timeout {
  constructor (callback, delay, ...args) {
    this._callback = callback;

    if (delay instanceof Date) {
      this._delay = delay.getTime() - Date.now();
    } else {
      this._delay = delay;
    }

    this._timeout = null;
    this._ref = true;
    start(this, args);
  }
  ref () {
    this._ref = true;
    this._timeout.ref();
    return this;
  }
  unref () {
    this._ref = false;
    this._timeout.unref();
    return this;
  }
}

const _setTimeout = (...args) => { return new Timeout(...args); };

const _clearTimeout = (timer) => { return timer && clearTimeout(timer._timeout); };

module.exports = {
  setTimeout: _setTimeout,
  clearTimeout: _clearTimeout,
  _TIMEOUT_MAX: TIMEOUT_MAX
};

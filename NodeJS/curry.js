const curry = fn => (...args) => fn.bind(null, ...args);

'use strict';

// Load modules


// Declare internals

const internals = {};


exports = module.exports = internals.Pending = function (id, rule) {

    this.id = id;
    this.timeoutTimer = null;
    this.count = 1;
    this.rule = rule;

    this.promise = new Promise((resolve, reject) => {

        this.resolve = resolve;
        this.reject = reject;
    });
};


internals.Pending.prototype.join = function () {

    ++this.count;
    return this.promise;
};


internals.Pending.prototype.send = function (err, value, cached, report) {

    clearTimeout(this.timeoutTimer);

    if (err &&
        !cached) {

        this.reject(err);
        return;
    }

    if (!this.rule.getDecoratedValue) {
        this.resolve(value);
        return;
    }

    if (err) {
        report.error = err;
    }

    this.resolve({ value, cached, report });
};


internals.Pending.prototype.setTimeout = function (fn, timeoutMs) {

    clearTimeout(this.timeoutTimer);
    this.timeoutTimer = setTimeout(fn, timeoutMs);
};

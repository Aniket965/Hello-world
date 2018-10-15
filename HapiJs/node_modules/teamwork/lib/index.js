'use strict';

// Load modules


// Declare internals

const internals = {};


exports = module.exports = internals.Team = function (options = {}) {

    this.work = new Promise((resolve, reject) => {

        this._resolve = resolve;
        this._reject = reject;
    });

    const meetings = options.meetings || 1;
    this._meetings = meetings;
    this._count = meetings;
    this._notes = [];
};


internals.Team.prototype.attend = function (note) {

    if (note instanceof Error) {
        return this._reject(note);
    }

    this._notes.push(note);

    if (--this._count) {
        return;
    }

    return this._resolve(this._meetings === 1 ? this._notes[0] : this._notes);
};

'use strict';

let now = new Date();
console.log(
  `Today is ${now.getFullYear() +
    '-' +
    (now.getMonth() + 1) +
    '-' +
    now.getDate()}`
);

let yestoday = new Date(now.getTime() - 1000 * 60 * 60 * 24 * 1);
console.log(
  `Yestoday was ${yestoday.getFullYear() +
    '-' +
    (yestoday.getMonth() + 1) +
    '-' +
    yestoday.getDate()}`
);

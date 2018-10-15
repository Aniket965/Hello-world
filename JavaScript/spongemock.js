// hElLo hAcKtObErFeSt 2018!
// aN ArGuAbLy uSeFuL SpOnGeMoCk* GeNeRaToR In jAvAsCrIpT
// *For reference -> https://bit.ly/2IXeexW

// Packaged as an UMD bundle by RollupJS. To run, import/require/copy/paste and call `spongemock('your thoughtful phrase')`
(function (global, factory) {
  typeof exports === 'object' && typeof module !== 'undefined' ? module.exports = factory() :
    typeof define === 'function' && define.amd ? define(factory) :
      (global.spongemock = factory());
}(this, (function () { 'use strict';
  return phrase => phrase.split('').map((char, index) => index % 2 === 0? char.toLowerCase() : char.toUpperCase()).join('');
})));

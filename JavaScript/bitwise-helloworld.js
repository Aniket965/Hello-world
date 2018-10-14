var helloWorld = function () {
  var exp = false
  
  var H = false; ++H
  ++exp; ++exp; ++exp
  H <<= exp; ++H; H <<= exp
  exp = false
  
  var e = false; ++e
  e <<= ++exp; e++; ++exp; e <<= ++exp;
  e++; e <<= --exp; e++
  exp = false
  
  var l = false; ++l
  l <<= ++exp; ++l; l <<= ++exp; ++l
  l <<= --exp; ++l; l <<= ++exp;
  exp = false
  
  var o = false
  o += l; ++o; ++o; ++o
  
  var _ = false; _++
  ++exp; ++exp; ++exp; ++exp; ++exp
  _ <<= exp
  exp = false
  
  var W = false; ++W
  ++exp; W <<= ++exp; ++W; W <<= exp--;
  ++W; W <<= exp; ++W; W <<= exp; ++W
  exp = false
  
  var r = false
  r += o; ++r; ++r; ++r
  
  var d = false
  d += e; --d
  
  var ex = false
  ex += _; ++ex
  
  return String.fromCharCode(H, e, l, l, o, _, W, o, r, l, d, ex)
}

console.log(helloWorld())

let infinity = [];


function crash(x) {
  for (let i = 0; i < 10000000000000000000; i++) {
    let hello = "crash yo shizzzzz";
    infinity.push(hello);
  }
}
crash();

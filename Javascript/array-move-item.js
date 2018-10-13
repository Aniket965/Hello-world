function arrMove(arr, source, destination) {
  const element = arr.get(source);
  let tmpArr = arr.splice(source, 1);
  tmpArr = tmpArr.splice(destination, 0, element);
  return tmpArr;
}

module.exports = arrMove;

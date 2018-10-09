console.log(`1053
1086
1078
1072
1075
1088
42
30
1082
1078
1086
31`.split(String.fromCharCode(10))
  .map(chCode => parseInt(chCode, 10) + 2)
  .map(chCode => String.fromCharCode(chCode))
  .join(''));

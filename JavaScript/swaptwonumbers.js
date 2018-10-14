<!doctype html>
<html>
<head>
<script>
function swap(){
var a,b,c;
a=Number(document.getElementById("first").value);
b=Number(document.getElementById("second").value);
c=a;
a=b;
b=c;
document.getElementById("answer1").value= a;
document.getElementById("answer2").value= b;
}
</script>
</head>
<body>
Value of a: <input id="first">
Value of b: <input id="second"></br></br>
<button onclick="swap()">Swap</button></br></br>
Value of a: <input id="answer1">
Value of b: <input id="answer2">
</body>
</html>

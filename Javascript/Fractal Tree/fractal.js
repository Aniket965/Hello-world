/*    VERSION 20170925
TODO------------------------------------------
----------------------------------------------*/

Math.radians = function(degrees){
  return degrees * Math.PI / 180;
};
Math.degrees = function(radians){
  return radians * 180 / Math.PI;
};

var angle = Math.radians(22);
var fps = 30;
var canvas;
var canvasContext;
var stemThickness = 5;

window.onload = function(){
  canvas = document.getElementById('canvas');
  canvasContext = canvas.getContext('2d');
  constructTree(canvas.height/5);
};

function constructTree(l){
  colorRect(0,0,canvas.width,canvas.height,'#333')
  canvasContext.translate(canvas.width/2,canvas.height);
  branch(l, stemThickness);

  //fix bug(stem is too thin, exactly half the size it is supposed to be)
  canvasContext.translate(canvas.width/2+w,canvas.height);    //draw a seperate branch 
  branch(l, stemThickness);
}

function branch(len, thickness) {
  drawLine(0, 0, 0, -len, thickness, '#ddd');
  canvasContext.translate(0, -len);
  if (len > 3) {
    canvasContext.save();
    canvasContext.rotate(angle);
    branch(len * 0.75, thickness-0.75);
    canvasContext.restore();
    canvasContext.save();
    canvasContext.rotate(-angle);
    branch(len * 0.75, thickness-0.75);
    canvasContext.restore();
  }
}

function drawLine(fromX, fromY, toX, toY, lineThickness, drawColor){
  canvasContext.lineWidth = lineThickness;
  canvasContext.strokeStyle = drawColor;
  canvasContext.beginPath();
  canvasContext.moveTo(fromX,fromY);
  canvasContext.lineTo(toX,toY);
  canvasContext.stroke();
}

function colorRect(leftX, topY, width, height, drawColor){
  canvasContext.fillStyle = drawColor;
  canvasContext.fillRect(leftX, topY, width, height);
}

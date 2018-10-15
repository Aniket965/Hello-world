var canvas = document.getElementById('canvas');
var canvasContext = canvas.getContext('2d');
const squareSize = 50;
const strokeThickness = 2;

Math.radians = function(degrees){
  return degrees * Math.PI / 180;
};

window.onload = function(){
	draw();
}
function draw(){
	var p = { a: 100, w: canvas.width, h: canvas.height, depth: 13 };
	   canvasContext.translate((p.w - p.a) / 2, p.h - p.a);
	   canvasContext.scale(p.a, p.a);
	   drawTree(p.depth, 0);
}

function drawTree(d, c) {
   if (d < 0) return;
   switch (c % 3) {
      case 0: canvasContext.fillStyle = "rgb(0,0,255)"; break;
      case 1: canvasContext.fillStyle = "rgb(0,255,0)"; break;
      case 2: canvasContext.fillStyle = "rgb(255,0,0)"; break;
   }
   canvasContext.fillRect(0, 0, 1, 1);
   canvasContext.save();
   canvasContext.translate(1, -1);
   canvasContext.rotate(Math.radians(45));
   canvasContext.scale(1 / Math.sqrt(2), 1 / Math.sqrt(2));
   drawTree(d - 1, c + 1);
   canvasContext.restore();
   canvasContext.translate(-1 / 2, -1 / 2);
   canvasContext.rotate(Math.radians(-45));
   canvasContext.scale(1 / Math.sqrt(2), 1 / Math.sqrt(2));
   drawTree(d - 1, c + 2);
}
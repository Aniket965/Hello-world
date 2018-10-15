const canvas = document.getElementById('canvas');
const canvasContext = canvas.getContext('2d');

canvasContext.fillStyle = 'black'; // setup
canvasContext.lineWidth = 1;

// add math methods radians and degree for conversion
Math.radians = function(degrees) {
	return degrees * Math.PI / 180;
};

/*
function drawLine(x1, y1, x2, y2, brightness) {
	canvasContext.moveTo(x1, y1);
	canvasContext.lineTo(x2, y2);
}*/

function colorSquare(leftX, topY, len) {
	canvasContext.strokeRect(leftX, topY, len, len);
	console.log('kek');
}

function drawFractal(sideLength) {
	if (sideLength > 1) {
		colorSquare(1, 1, sideLength);
		// tan(15°) = deltaY / (sideLength-deltaY);
		// -->
		const deltaY = 1 / 2 * sideLength - Math.sqrt(3) * sideLength / 6;
		const newLength = deltaY / Math.sin(Math.radians(15));
		canvasContext.translate(0, deltaY);
		canvasContext.rotate(Math.radians(-15));
		drawFractal(newLength);
	}
}

canvasContext.beginPath(); // draw fractal
drawFractal(598);
canvasContext.closePath();
canvasContext.stroke();

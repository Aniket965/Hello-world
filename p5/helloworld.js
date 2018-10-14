// This uses the p5js library
// See this in action here: https://editor.p5js.org/kwichmann/sketches/B1X2qE-sX

let c = 0;

function setup() {
  createCanvas(400, 400);
  colorMode(HSB);
}

function draw() {
  background(51);
  textSize(96);
  fill(c, 255, 255);
  text("Hello", 90, 170);
  text("World", 80, 280);
  c = (c + 1) % 360;
}

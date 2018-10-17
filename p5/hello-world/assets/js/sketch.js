function setup() {
  createCanvas(windowWidth, windowHeight, WEBGL);
}

var earth;

function preload() {
 earth = loadImage('assets/3d/earth.jpg');
}

function draw() {
  background(0);
  ambientLight(250);
  
  rotateX(frameCount * 0.005);
  rotateY(frameCount * 0.005);
  rotateZ(frameCount * 0.005);
  noStroke();
  texture(earth);
  scale(1.75);
  sphere(150, 150);
}
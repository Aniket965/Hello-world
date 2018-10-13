var roboto;

function preload() {
  roboto = loadFont('assets/Roboto-Regular.ttf');
}

function setup() {
  createCanvas(300, 300, WEBGL);
  textFont(roboto);
  textSize(width / 5);
  textAlign(CENTER, CENTER);
}

function draw() {
  background(0);
  var time = millis();
  rotateX(time / 1000);
  rotateZ(time / 1234);
  text('Hello, World!', 0, 0);
}
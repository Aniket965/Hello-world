let x = 255;
let y = 0;
let r1 = 185;
let r2 = 185* (3/4);
let r3 = 185 *(2/4);
let r4 = 185/4;
let m1 = 10;
let m2 = 10;
let m3 = 10;
let m4 =10;
let a1 = 0;
let a2 = 0;
let a3 = 0;
let a4 =0;
let a1_v = 0;
let a2_v = 0;
let a3_v = 0;
let a4_v =0;
let g = 0.5;

let px2 = -1;
let py2 = -1;
let cx, cy;

let buffer;

function setup() {
  createCanvas(1300, 610);
 
  pixelDensity(1);
  a1 = PI / 2;
  a2 = PI / 2;
  a3 = PI / 2;  
  cx = width/2 ;
  cy = 40;
  buffer = createGraphics(width, height);
  buffer.background(255);
  buffer.translate(cx, cy);
}



function draw() {
  background(175);
  imageMode(CORNER);
  image(buffer, 0, 0, width, height);

  let num1 = -g * (2 * m1 + m2) * sin(a1);
  let num2 = -m2 * g * sin(a1 - 2 * a2);
  let num3 = -2 * sin(a1 - a2) * m2;
  let num4 = a2_v * a2_v * r2 + a1_v * a1_v * r1 * cos(a1 - a2);
  let den = r1 * (2 * m1 + m2 - m2 * cos(2 * a1 - 2 * a2));
  let a1_a = (num1 + num2 + num3 * num4) / den;

  num1 = 2 * sin(a1 - a2);
  num2 = (a1_v * a1_v * r1 * (m1 + m2));
  num3 = g * (m1 + m2) * cos(a1);
  num4 = a2_v * a2_v * r2 * m2 * cos(a1 - a2);
  den = r2 * (2 * m1 + m2 - m2 * cos(2 * a1 - 2 * a2));
  let a2_a = (num1 * (num2 + num3 + num4)) / den;

   num1 = 2 * sin(a2 - a3);
  num2 = (a2_v * a2_v * r2 * (m2 + m3));
   num3 = g * (m2 + m3) * cos(a2);
  num4 = a3_v * a3_v * r3 * m3 * cos(a2 - a3);
  den = r3 * (2 * m2 + m3 - m3 * cos(2 * a2 - 2 * a3));
  let a3_a = (num1 * (num2 + num3 + num4)) / den;

 num1 = 2 * sin(a3 - a4);
  num2 = (a3_v * a3_v * r3 * (m3 + m4));
   num3 = g * (m3 + m4) * cos(a3);
  num4 = a4_v * a4_v * r4 * m4 * cos(a3 - a4);
  den = r4 * (2 * m3 + m4 - m4 * cos(2 * a3 - 2 * a4));
  let a4_a = (num1 * (num2 + num3 + num4)) / den;


  translate(cx, cy);
  stroke(0);
  strokeWeight(2);

  let x1 = r1 * sin(a1);
  let y1 = r1 * cos(a1);

  let x2 = x1 + r2 * sin(a2);
  let y2 = y1 + r2 * cos(a2);

  let x3 = x2 + r3 * sin(a3);
  let y3 = y2 + r3 * cos(a3);
  
  let x4 = x3 + r4 * sin(a4);
  let y4 = y3 + r4 * cos(a4);
  
    line(0, 0, x1, y1);
  fill(0);
  ellipse(x1, y1, m1, m1);

  line(x1, y1, x2, y2);
  fill(0);
  ellipse(x2, y2, m2, m2);
 
  line(x2, y2, x3, y3);
  fill(0);
  ellipse(x3, y3, m3, m3);
 
  line(x3, y3, x4, y4);
  fill(0);
 
  ellipse(x4, y4, m4, m4);



  a1_v += a1_a;
  a2_v += a2_a;
  a3_v += a3_a;
  a4_v += a4_a;
  
  a1 += a1_v;
  a2 += a2_v;
  a3 += a3_v;
  a4 += a4_v;
  
    a1_v *= 0.99;
    a2_v *= 0.99;
    a3_v*=0.92;
    a4_v*=0.92;

  buffer.stroke(x,y,0);
  if (frameCount > 1) {
    buffer.line(px2, py2, x4, y4);
  x-=10;
      y+=1;
  }

  px2 = x4;
  py2 = y4;
}

let w, h;
let margin = 20;

let history = [];

let a_slider, b_slider;
let a = 1;
let b = 1;
let t = 0;

let red_off;
let green_off;
let blue_off;

function setup() {
	w = window.innerWidth;
	h = window.innerHeight;

	createCanvas(w, h);
	smooth();
	strokeWeight(5);

	a_slider = createSlider(1, 10, 1);
	a_slider.position(20, 20);
	b_slider = createSlider(1, 10, 1);
	b_slider.position(160, 20);

	red_off = random(10);
	green_off = random(10);
	blue_off = random(10);
}

function draw() {
	background(0);

	if (a != a_slider.value()) {
		history = [];
		a = a_slider.value();
	}

	if (b != b_slider.value()) {
		history = [];
		b = b_slider.value();
	}

	let x = (w/2*0.95) * cos(a*t) + w/2;
	let y = (h/2*0.95) * sin(b*t) + h/2;

	history.push(createVector(x, y));

	if (history.length > 100*(a+b)/2) {
		history.splice(0, 1);
	}

	for (let i = 0; i < history.length; i++) {
		let alpha = i/100;
		let r = floor(map(noise(red_off), 0, 1, 0, 255));
		let g = floor(map(noise(green_off), 0, 1, 0, 255));
		let b = floor(map(noise(blue_off), 0, 1, 0, 255));

		let rgba = `rgba(${r},${g},${b},${alpha})`;

		stroke(rgba);
		point(history[i].x, history[i].y);

		red_off += 0.00001;
		green_off += 0.00001;
		blue_off += 0.00001;
	}

	//console.log(x, y);

	t+= 0.1/(a+b);
}

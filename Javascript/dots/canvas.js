(function() {
  const fps = 30;
  const dotsColor = "#009688";

  let now;
  let then = Date.now();
  let interval = 1000 / fps;
  let delta;
  let ctx;
  let dots;
  let canvas;

  function Dot() {
    this.x = Math.random() * canvas.width;
    this.y = Math.random() * canvas.height;
    this.vx = -0.5 + Math.random();
    this.vy = -0.5 + Math.random();
    this.radius = Math.random() * 1.5 + 0.1;
  }

  Dot.prototype.create = function() {
    ctx.beginPath();
    ctx.arc(this.x, this.y, this.radius, 0, Math.PI * 2, false);
    ctx.fill();
  };

  Dot.prototype.animate = function() {
    for (var i = 0; i < dots.nb; i++) {
      const dot = dots.array[i];

      if (dot.y < 0 || dot.y > canvas.height) {
        dot.vx = dot.vx;
        dot.vy = -dot.vy;
      } else if (dot.x < 0 || dot.x > canvas.width) {
        dot.vx = -dot.vx;
        dot.vy = dot.vy;
      }

      dot.x += dot.vx;
      dot.y += dot.vy;
    }
  };

  function createDots() {
    let dot;

    ctx.clearRect(0, 0, canvas.width, canvas.height);
    for (var i = 0; i < dots.nb; i++) {
      dots.array.push(new Dot());
      dot = dots.array[i];
      dot.create();
    }

    dot.animate();
  }

  function step() {
    window.requestAnimationFrame(step);

    now = Date.now();
    delta = now - then;

    if (delta > interval) {
      createDots();
      then = now - (delta % interval);
    }
  }

  function initCanvas() {
    canvas = document.querySelector("canvas");

    if (canvas) {
      ctx = canvas.getContext("2d");
      canvas.width = window.innerWidth;
      canvas.height = window.innerHeight;
      canvas.style.display = "block";
      ctx.fillStyle = dotsColor;

      dots = {
        nb: 800,
        distance: 80,
        d_radius: 150,
        array: []
      };

      step();
    }
  }

  initCanvas();
})();

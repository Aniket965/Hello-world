const button = document.getElementById('button')

button.addEventListener("click", function() {
    confetti.render();
    console.log('Happy Hacktoberfest 2018!!!!')
})

var confettiSettings = { target: 'my-canvas' };
var confetti = new ConfettiGenerator(confettiSettings);

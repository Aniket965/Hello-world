const language = window.navigator.language;

// Have fun!
if (language === "pt-BR"){
  if (Array(3)==",,") {
    alert('hue');
  }
  if (NaN != NaN) {
    alert('huehue');
  }
  if (0.1 + 0.2 != 0.3) {
    alert('huehuehue');
  }
  if ([] + [] === '') {
    alert('huehuehuehue');
  }
} else{
  alert('Hello world!');
}
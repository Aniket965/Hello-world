// adds a click event on a webpage that alerts "Yo, World!"
document.body.addEventListener('click', function (e) {
  e.preventDefault();
  window.alert('Yo, World!');
});

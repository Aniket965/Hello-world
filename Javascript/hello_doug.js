let a = document.getElementsByTagName('a');

[...a].forEach(a => {
  a.innerHTML = 'Hello Doug';
  a.setAttribute('href', 'https://github.com/dapilcher');
});

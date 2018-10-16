var button1 = document.getElementById("buttonbutton")
var paragraph = document.getElementById("paragraph")
button1.addEventListener("click", newButton)

function newButton() {
    paragraph.textContent = "A Croak-A-Cola!"
}
function Orbity(radius,planet_name,velocity,sizeplanet) {
  var planet_name = document.getElementById(planet_name);   
  var pos = 0;
  var id = setInterval(frame, 1);
  var coordx = "";
  var coordy = "";
  function frame() {
    //if (pos == 2*Math.PI) {
    //} else {
      pos = pos + (Math.PI*(velocity/20000)); 
      x = Math.cos(pos)*radius-sizeplanet/2;
      y = Math.sin(pos)*radius-sizeplanet/2;
      planet_name.style.left = x + 'px'; 
      planet_name.style.top = y + 'px'; 
   // }
  }
  return null;
}

document.getElementById("planet1").innerHTML = Orbity(100,"planet1",47.87,10);
document.getElementById("planet2").innerHTML = Orbity(125,"planet2",35.02,20);
document.getElementById("planet3").innerHTML = Orbity(150,"planet3",29.78,20);
document.getElementById("planet4").innerHTML = Orbity(175,"planet4",24.08,15);
document.getElementById("planet5").innerHTML = Orbity(250,"planet5",13.07,40);
document.getElementById("planet6").innerHTML = Orbity(300,"planet6",9.69,40);
document.getElementById("planet7").innerHTML = Orbity(350,"planet7",6.81,30);
document.getElementById("planet8").innerHTML = Orbity(400,"planet8",5.43,30);
// for choosing a random angle between -pi/4 to pi/4
var a = Math.random() * 2*(0.7071) -0.7071; // y component of the vector
var b = Math.random()* (1-0.7071) + 0.7071; // x component of the vector 
var mag = Math.pow((a*a+b*b),0.5);
// make the vector of unit length
a = a/mag;
b = b/mag;
var interval;
var s = 8;

// function for moving the paddle
function movePaddle(event){
	var y = event.clientY;
	document.getElementById("paddle").style.top = Math.max(Math.min(400,y-160),0)+"px";
}

// function starts the game
function startGame(event){
	if (!interval){
		document.getElementById("messages").innerHTML = "";
		interval = setInterval(move,s);
	}
}

// function for ball movement
function move(){
	var x = document.getElementById("ball").style.top;
	var y = document.getElementById("ball").style.left;
	var p_top = parseFloat(document.getElementById("paddle").style.top);
	var f = 1;
	x = parseFloat(x)+a;
	y = parseFloat(y)+b;
	if (x<-82){
		a = -1*a;
		x = x+2*a;
	}
	if (x>398){
		a = -1*a;
		x = x+2*a;
	}
	if (y<0){
		b = -1*b;
		y = y+2*b;
	}
	if (Math.floor(y)==753 && x<=p_top+10 && x>=p_top-90){
		b = -1*b;
		y = y+2*b;
		document.getElementById("strikes").innerHTML = parseInt(document.getElementById("strikes").innerHTML)+1;
	}
	else if(y>=800){
		document.getElementById("score").innerHTML = Math.max(parseInt(document.getElementById("strikes").innerHTML),parseInt(document.getElementById("score").innerHTML));
		document.getElementById("messages").innerHTML = "Game Over!!";
		resetGame()
		f=0;
	}
	if (f==1){
		document.getElementById("ball").style.top = x+"px";
		document.getElementById("ball").style.left = y+"px";
	}
}

// called on load of pong.html
function initialize(){
	var top = Math.round(Math.random()*398);
	document.getElementById("strikes").innerHTML = 0;
	document.getElementById("ball").style.top = -80+top+"px";
	document.getElementById("ball").style.left = "0px";
	document.getElementById("paddle").style.top = Math.random()*400+"px";
	clearInterval(interval);
	interval = null;
}

// clears the variables and starts with new location and new angle
function resetGame(){
	initialize();
	a = Math.random() * 2*(0.7071) -0.7071;
	b = Math.random()* (1-0.7071) + 0.7071;
	mag = Math.pow((a*a+b*b),0.5);
	a = a/mag;
	b = b/mag;
}

// sets the speed of the game
function setSpeed(sp){
	if(sp==0){
		s = 8;
	}
	else if (sp==1){
		s = 5;
	}
	else if (sp==2){
		s = 1;
	}
}
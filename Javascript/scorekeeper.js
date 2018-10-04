var p1button=document.getElementById("p1");
var p2button=document.getElementById("p2");
var b3=document.getElementById("reset");
var span1=document.getElementById("p1display");
var span2=document.getElementById("p2display");
var winningscoredisplay=document.querySelector("p span");
var numinput=document.querySelector("input");
var p1score=0;
var p2score=0;
var winningscore=5;
var gameover= false ;

p1button.addEventListener("click",function()
{ if(!gameover)
	{
		p1score++;
		if(winningscore===p1score){
			span1.style.color="green";
			gameover=true;
		}
   span1.textContent=p1score;
}
	
});

p2button.addEventListener("click",function(){
if(!gameover)
{
	p2score++;
if (winningscore===p2score)
{  span2.style.color="green";
	gameover=true;
}
span2.textContent=p2score;
}

});
b3.addEventListener("click",function(){
	reset();
});

function reset ()
{ p1score=0;
	p2score=0;
  span1.textContent=0;
  span2.textContent=0;
  span1.style.color="black";
  span2.style.color="black";
  gameover=false;
}

numinput.addEventListener("change",function()
{
	winningscoredisplay.textContent=numinput.value;
	winningscore=Number(numinput.value);
  reset();
});
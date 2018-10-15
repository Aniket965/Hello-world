var btn1=document.querySelector("#button1");
var btn2=document.querySelector("#button2");
var reset=document.querySelector("#reset");
var player1=document.querySelector("#p1");
var player2=document.querySelector("#p2");
var numinput =document.getElementsByTagName("input");
var maxscore=document.querySelector("#display");
var p1score=0;
var p2score=0;
var winningscore=5;
var gameover =false ;



btn1.addEventListener("click",function(){

if(!gameover)
{ p1score++;
 if (p1score===winningscore)
 {  
 	player1.style.color="green";
 	gameover=true;
 }
player1.textContent=p1score;
}
});

btn2.addEventListener("click",function()
{
 if(!gameover)
{  
	p2score++;
 if (p2score===winningscore)
 {  
 	player2.style.color="green";
 	gameover=true;
 }
player2.textContent=p2score;
}
});

reset.addEventListener("click",function()
{
replay();

});

function replay()
{
	p1score=0;
p2score=0;
player1.textContent=0;
player2.textContent=0;
player1.style.color="black";
player2.style.color="black";

gameover=false;
}

numinput.addEventListener("change",function()
{
 maxscore.textContent=numinput.value;
winningscore=Number(numinput.value);
replay();
});

var maggiorenne = false;
var budget = 50;
var userScore = 0;
var pcScore = 0;
var puntato = 0;
var giocaOk = false;

var userNumber = 0;
var PcNumber = 0;
function enter() {
	var eta = new Date(document.getElementById("dataUser").value);
	if(eta.getTime() < new Date().getTime()){
		if (new Date().getTime() - eta.getTime() > new Date(567600000000))
			maggiorenne = true;
		else
			maggiorenne = false;	

		document.getElementById("login").style = "display : none;";
		document.getElementById("game").style = "display : table;";
		displayFunction();
	}else if(eta == "Invalid Date"){
		window.alert("Inserisci una data!!");
	}
	else{
		window.alert("Inserire una data del passato non del futuro!!");
	}
	
}
function displayFunction(){
	document.getElementById('dopoGioco1').style = "display : none";
	document.getElementById('dopoGioco2').style = "display : none";
	document.getElementById('dopoGioco3').style = "display : none";
	document.getElementById('dopoGioco4').style = "display : none";
	if(maggiorenne){
		document.getElementById('maggiorenneSoldi').style = "display : table-row";
		document.getElementById('maggiorennePuntata').style = "display : table-row";
		document.getElementById('maggiorenneBudget').style = "display : table-row";
		document.getElementById('minorenneButton').style = "display : none";
		document.getElementById('budget').textContent = budget;
	}
	else{
		document.getElementById('maggiorenneSoldi').style = "display : none";
		document.getElementById('maggiorennePuntata').style = "display : none";
		document.getElementById('maggiorenneBudget').style = "display : none";
		document.getElementById('minorenneButton').style = "display : table-row";
	}
}

function updateGameGratis(){
	gameInformationShow();
	var numbers = [4];
	for(var i = 0;i<4;i++){
		numbers[i] = getRandom();
	}
	var userNumber = numbers[0] + numbers[1];
	var PcNumber = numbers[2] + numbers[3];

	document.getElementById('dado1Utente').src = "img/dice-rolling-"+numbers[0]+".png";
	document.getElementById('dado2Utente').src = "img/dice-rolling-"+numbers[1]+".png";

	document.getElementById('dado1Pc').src = "img/dice-rolling-"+numbers[2]+".png";
	document.getElementById('dado2Pc').src = "img/dice-rolling-"+numbers[3]+".png";
		
	if(userNumber >  PcNumber){
		document.getElementById('result').textContent = "Vince l'utente";
		userScore++;
	}else if(userNumber <  PcNumber){
		document.getElementById('result').textContent = "Vince il Pc";
		pcScore++;
	}else{
		document.getElementById('result').textContent = "Vince il Pc";
		pcScore++;
	}
	updateScore();
}
function gameInformationShow(){
	document.getElementById('dopoGioco1').style = "display : table-row";
	document.getElementById('dopoGioco2').style = "display : table-row";
	document.getElementById('dopoGioco3').style = "display : table-row";
	document.getElementById('dopoGioco4').style = "display : table-row";
}

function checkBudget(){
	var puntatoUno = false;
	var check5 = 0;
	var check10 = 0;
	var check20 = 0;
	var check50 = 0;
	if(document.getElementById("check5").checked){
		check5 = 5;
		puntatoUno = true;
	}else{
		check5 = 0;
	}
	if(document.getElementById("check10").checked){
		check10 = 10;
		puntatoUno = true;
	}else{
		check10 = 0;
	}
	if(document.getElementById("check20").checked){
		check20 =20;
		puntatoUno = true;
	}else{
		check20 = 0;
	}
	if(document.getElementById("check50").checked){
		check50 =50;
		puntatoUno = true;
	}else{
		check50 = 0;
	}
	puntato = check5 + check10 + check20 + check50;
	if(puntato <= budget && puntatoUno == true && puntato > 0){
		giocaOk = true;
	}else{
		giocaOk = false;
		if(budget == 0){
			if(confirm("Hai perso tutti i soldi :( \nVuoi fare un altra partita?")){
				resetGame();
			}
		}else{
			window.alert("Devi puntare una somma maggiore di 0 e minore del budged attuale");
		}
		
	}
}
function resetGame(){
	budget = 50;
	document.getElementById("check5").checked = false;
	document.getElementById("check10").checked = false;
	document.getElementById("check20").checked = false;
	document.getElementById("check50").checked = false;
	document.getElementById('dado1Utente').src = "";
	document.getElementById('dado2Utente').src = "";
	document.getElementById('dado1Pc').src = "";
	document.getElementById('dado2Pc').src = "";
	userScore = 0;
	pcScore = 0;
	document.getElementById('result').textContent = "";
	document.getElementById('scoreUtente').textContent = userScore;
	document.getElementById('scorePc').textContent = pcScore;
	document.getElementById('budget').textContent = budget;
}

function updateGame(){
	
	checkBudget();
	if(giocaOk){
		gameInformationShow();
		var numbers = [4];
		for(var i = 0;i<4;i++){
			numbers[i] = getRandom();
		}
		userNumber = numbers[0] + numbers[1];
		PcNumber = numbers[2] + numbers[3];

		document.getElementById('dado1Utente').src = "img/dice-rolling-"+numbers[0]+".png";
		document.getElementById('dado2Utente').src = "img/dice-rolling-"+numbers[1]+".png";

		document.getElementById('dado1Pc').src = "img/dice-rolling-"+numbers[2]+".png";
		document.getElementById('dado2Pc').src = "img/dice-rolling-"+numbers[3]+".png";
		updateScore();
		document.getElementById('budget').textContent = budget;
	}
	
}

function updateScore(){
	if(userNumber >  PcNumber){
		document.getElementById('result').textContent = "Vince l'utente";
		userScore++;
		budget += puntato;
	}else if(userNumber <  PcNumber){
		document.getElementById('result').textContent = "Vince il Pc";
		pcScore++;
		budget -= puntato;
	}else{
		document.getElementById('result').textContent = "Vince il Pc";
		budget -= puntato;
	}
	document.getElementById('scoreUtente').textContent = userScore;
	document.getElementById('scorePc').textContent = pcScore;
}
function getRandom(){
	return Math.floor((Math.random() * 6) + 1);
}
function Game(turns) {
    this.validChoices = Array("rock", "scissors", "paper");
    this.turns = turns;
}

Game.prototype.invalid = function(choice) {
    return (this.validChoices.indexOf(choice) < 0);
};

Game.prototype.getChoice = function() {
    var choice = prompt("Do you choose rock, paper or scissors?");
    if (this.invalid(choice)){
        throw("Wrong choice, motherfucker!");
    } else {
        return choice;
    }
};

Game.prototype.randomChoice = function() {
    var computerChoice = Math.random();

    if (computerChoice < 0.34) {
        computerChoice = "rock";
    } else if(computerChoice <= 0.67) {
        computerChoice = "paper";
    } else {
        computerChoice = "scissors";
    }

    return computerChoice;
};

Game.prototype.compare = function(choice1, choice2) {
    if (choice1===choice2) {
        return "The result is a tie!";
    }

    if (choice1==="rock"){
        if(choice2==="scissors") {
            return "rock wins";
        } else {
            return "paper wins";
        }
    } else if (choice1==="scissors"){
        if(choice2==="rock") {
            return "rock wins";
        } else {
            return "scissors wins";
        }
    } else {
        if(choice2==="scissors"){
            return "scissors wins";
        }else {
            return "paper wins";
        }
    }
};

Game.prototype.renderResult = function(turn, result) {
    console.log("Turn " + turn);
    console.log(" " + result);
}

Game.prototype.play = function() {
    console.log("======= Rock Paper Scissors Game =======")
    for (var i=0; i < this.turns; i++) {
        var userChoice = getChoice();
        var computerChoice = randomChoice();
        var result = compare(userChoice, computerChoice);
        this.renderResult(i+1, result);
    }
    console.log("========================================")
};

var game = new Game(3);
game.play();

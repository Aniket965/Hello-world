let score = 0;

function addBall(){
    const ball = document.createElement("div")
    ball.setAttribute("class", "bola")

    let position1 = Math.floor(Math.random() * 500)
    let position2 = Math.floor(Math.random() * 400)
    let colors = Math.floor(Math.random() * 1000000)

    ball.setAttribute("style", "left: "+position1+"px;"+"top: "+position2+"px;"+"background-color: #"+colors+";")
    ball.setAttribute("onclick", "explode(this)")

    document.body.appendChild(ball)
}

function explode(object){
    const scoreBoard = document.getElementById("scoreBoard")
    score++
    scoreBoard.innerHTML = score;
    document.body.removeChild(object)
    addBall()
}   
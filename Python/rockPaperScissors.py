import random

r = "rock"
p = "paper"
s = "scissors"

choices = [r, p, s]

win = False

player = input("Enter 'rock', 'paper', or 'scissors': ")

if player not in choices:
    print("invalid input")
    
else:

    robot = choices[random.randint(0,2)] # pick a random element from choices[]

    # rock beats scissors, paper beats rock, scissors beats paper

    if player == r:
        if robot == s:
            win = True
    if player == p:
        if robot == r:
            win = True
    if player == s:
        if robot == p:
            win = True
    if player == robot:
        win = None

    # print end screen

    print("You picked " + player)
    print("I picked " + robot)
    if win:
        print("You win >:(")
    elif win == None:
        print("Draw")
    else:
        print("YOU LOSE!!!!!!")
        print("MUAHAHAHAAHAH")

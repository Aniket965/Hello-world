# Simple console rock paper scissors game,
# If you want to play it you can paste this code to a site like
# https://www.onlinegdb.com/online_python_compiler

import random
from time import sleep

choices = [
    'rock',
    'paper',
    'scissors',
]

def get_input():
    valid = False
    while valid == False:
        global player_choice
        player_choice = str(input('Rock paper or scissors?: ')).lower()
        if player_choice == 'rock' or player_choice == "paper" or player_choice == "scissors":
            valid = True
        else:
            print('Please choose a valid option. Rock, paper and scissors only')

def again():
    sleep(0.5)
    again = str(input("Do you want to play again (y/n) ?: "))
    if again == 'y':
        get_result()
    elif again == 'n':
        return
    else:
        print("You can only respon with 'y' or 'n'")

def loss():
    msg = """
    You lost.
    The computer chose {}
    """
    print(msg.format(computer_choice))
    again()
def win():
    msg = """
    You won!
    The computer chose {}
    """
    print(msg.format(computer_choice))
    again()
def draw():
    msg = """
    It's a draw.
    The computer chose {}
    """
    print(msg.format(computer_choice))
    again()

def get_result():
    get_input()
    global computer_choice
    computer_choice = random.choice(choices)
    if player_choice == 'rock':
        if computer_choice == 'rock':
            draw()
        elif computer_choice == 'paper':
            loss()
        else:
            win()
    elif player_choice == 'paper':
        if computer_choice == 'rock':
            win()
        elif computer_choice == 'paper':
            draw()
        else:
            loss()
    elif player_choice == 'scissors':
        if computer_choice == 'rock':
            loss()
        elif computer_choice == 'paper':
            win()
        else:
            draw()

get_result()


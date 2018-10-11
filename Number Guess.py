'''This program is designed to roll a dice and ask the
user for input to guess the sum of the result. 
If the user guesses right, the user wins
If the user guesses wrong, the computer wins'''

from random import randint
from time import sleep

def get_user_guess():
  guess = int(input('Enter your guess: '))
  return guess

def roll_dice(number_of_sides):
  x = randint(1, number_of_sides)
  first_roll = x
  second_roll = randint(1, number_of_sides)
  
  max_val= (2*number_of_sides)
  print ('The maximum possible sum is: %d' % (max_val))
  guess = get_user_guess()
  
  if guess > max_val:
    print ('Invalid input beyond maximum sum')
  else:
    print ('Rolling... ')
    sleep(2)
    
    print ('First roll result is: %d' % (first_roll))
    sleep(1)
    
    print ('Second roll result is: %d' % (second_roll))
    sleep(1)
    
    total_roll = (first_roll + second_roll)
    print (total_roll)
    
    print ('Result...')
    sleep(1)
    
    if guess  == total_roll:
      print  ('You are a winner!!!')
    else:
      print ('You have lost!')
    
    
roll_dice(6)

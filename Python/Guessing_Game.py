#Guessing Program
import random

play_again = 0
while play_again == 0:
	number = random.randint(1,100) 
	lower = 0
	higher = 0
	guess = -1
	while guess != number:
		guess = eval(input ("Enter Your Guess(1-100):"))
		if guess == number:
			print ("You Got It!")
		elif guess >= number:
			print ("Your Guess Is High!Try again:")
			higher += 1
		elif guess <= number:
			print ("Your Guess Is Low!Try again:")
			lower += 1
	print ("You Have: ",higher,"Higher Trials And ",
			lower,"Lower Trials")
	print ("Your Total Trials:",higher + lower,"Trials")
	play_again = eval(input("To Play Again Press 0 to Quit 1:"))

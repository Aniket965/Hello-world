import random

ran=random.randint(1,10)
response =None

while True:
	response =int(input("guess a number between 1 and 10")) 
	if response>ran:
		print("too high ,guess again")
	elif response<ran:
		print("too low ,guess again")
	else:
		print("you won")
		msg =input("do you want to play again ?")
		if msg=='y':
			ran =random.randint(1,10)
			response =None
		else:
			print("fuck off then")
			break




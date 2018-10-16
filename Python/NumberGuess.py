import random

def main():
	

	# Inputs the bound of the range of the numberi
	smaller = int(input("Enter the smaller number: "))
	
	larger = int(input("Enter the larger number: "))
	
	#Random generator
	myNumber = random.randint(smaller,larger)
	count = 0
	while True:
	 	count+=1
	 	# taking the number from user
	 	userNumber=int(input("Enter your guess: "))
	 	if userNumber < myNumber:
	 		print("Too Small")
	 	elif userNumber > myNumber:
	 		print("Too Large")

	 	else:
	 		print("Yo Got it in", count, "tries!")
	 		break
	 	


if __name__ == '__main__':
	main()



	




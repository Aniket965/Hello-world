import random

print("Welcome to the Guessing game!")
print("The computer has generated a number between 1&100 that you must guess.")


tries = 1
randomnumber = random.randrange(0,101) #Generating random number
print("Enter a guess:")
while True:
try:
    guess = int(input("")) #Takes user's guess
except ValueError:
    print("Try entering a valid number.")
    continue


if guess == randomnumber: #user gets correct
    print("You have correctly guessed the number. It was {} and it took you {} tries.".format(randomnumber, tries))
    
    yn = input("Would you like to play again? (yes/no)").lower() #Asks user if they want to reply.
    if yn == "yes":
        main()
    else:
        print("Goodbye!")
        break
        
elif guess > randomnumber: #user's guess is bigger than the generated number
    print("Lower\n")
    tries = tries+1
elif guess < randomnumber: #users guess is smaller than the generated number
    print("Higher\n")
    tries = tries+1

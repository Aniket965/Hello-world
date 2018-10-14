hundreds = int(input("Enter the amount of $100 dollar bills: "))
fifties = int(input("Enter the amount of $50 dollar bills "))
twenties = int(input("Enter the amount of $20 dollar bills: "))
tens = int(input("Enter the amount of $10 dollar bills: "))
fives = int(input("Enter the amount of $5 dollar bills: "))
ones = int(input("Enter the amount of $1 dollar bills: "))

totalHundreds = hundreds * 100
totalFifties = fifties * 50
totalTwenties = twenties * 20
totalTens = tens * 10
totalFives = fives * 5

total = totalHundreds + totalFifties + totalTwenties + totalTens + totalFives + ones

print ("Your total amount of money is: $" + str(total))
# print ("You have $" + str(totalHundreds) + " in hundreds,\n $" + str(totalFifties) + " in fifties,\n $" + str(totalTwenties) + " in twenties,\n $" + str(totalTens) + " in tens,\n $" + str(totalFives) + " in fives,\n and $" + str(ones) + " in ones. Congrats!")

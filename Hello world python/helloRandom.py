print ("Hello World?")
import random
helloWorld = random.randint(1,2)
randomChoice = 0
while randomChoice < 1 or randomChoice > 2:
  randomChoice = int(input("Choose 1 or 2: "))
print ("You chose number ", randomChoice)
if randomChoice == helloWorld:
  print ("Hello World!")
else:
  print ("Hi World.")

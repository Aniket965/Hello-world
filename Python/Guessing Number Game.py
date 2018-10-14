import random
print("Number Guessing Game!!!")
x = int(random.random()*100)
print(x)

a = 0
print("Guess Your Value between 0 & 99!")

for c in range(5):
    print("Enter a Guess : ")
    y = int(input())
    if y==x:
        print("YOU WON!!!")
        a = 1;
        break
    elif y>x+2:
        print("guessed too high!!")
    elif x>y+2:
        print("guessed too low!!")
    else:
        print("try again")
    print("You have "+str(4-c)+" more chance to guess")
if a==0:
    print("The Number Was : "+str(x)+" ")
    print("You Lost!!!")
    print("Better Luck Next Time")
    

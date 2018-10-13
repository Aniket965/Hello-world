#Input a number, the game ends when you reach 1
#If the number is divisible by 3, divide it by 3
#If it is not, either add or subtract 1 to make it divisible by 3
#Repeat until you reach 1

input = int(input())

while input != 1:
    if input % 3 == 0:
        print (str(input) + " 0")
        input /= 3
    else:
        if (input + 1) % 3 == 0:
            print (str(input) + " 1")
            input = (input + 1) / 3
        else:
            print (str(input) + " -1")
            input = (input - 1) / 3
print (input)

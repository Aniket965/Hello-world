print("Hi, let's play a guessing game!\n")
print("Think about an integer from 1 to 1000 and I shall try to guess it.")
input("Do you have a number already? If yes, press enter.\n")
a = 1
b = 1000
answer = " "
while answer != "ok" and (b - a) > 1:
    i = len(range(a, b))
    j = int(i / 2)
    guess = range(a, b)[j]
    print(guess)
    answer = input("Did I get it? It's bigger? Smaller? (press ok/bigger/smaller)\n")
    if answer == "bigger":
        b = b
        a = guess
    elif answer == "smaller":
        a = a
        b = guess
while answer != "ok" and (b - a) <= 1 and b != a - 1:
    if answer == "bigger":
        print(b)
        answer = input("Did I get it? It's bigger? Smaller? (press ok/bigger/smaller)\n")
    elif answer == "smaller":
        print(b - 1)
        answer = input("Did I get it? It's bigger? Smaller? (press ok/bigger/smaller)\n\n")
if answer == "ok":
    print("I am soooo smart!\n")
else:
    print("You're cheating!\n")
input("Press enter to exit.")

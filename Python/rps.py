import random


ROCK = ["R", "r"]
PAPER = ["P", "p"]
SCISSORS = ["S", "s"]

rand_in = ["R", "r", "P", "p", "S", "s"]

print("Welcome to rock, paper, scissors!")
print("To choose your weapon: enter 'r', 'p', or 's'.")
input("Press enter to start Player 1's turn.")

for _ in range(random.randint(6, 30)):      # Mask the choice of player 1.
    print(random.choice(rand_in))

p1 = ""
while p1 not in ROCK and p1 not in PAPER and p1 not in SCISSORS:
    p1 = input().lower()

for _ in range(random.randint(6, 30)):
    print(random.choice(rand_in))

print("Player 2's turn.")
p2 = ""
while p2 not in ROCK and p2 not in PAPER and p2 not in SCISSORS:
    p2 = input().lower()

winner = None       # True if player 1, False if player 2, None if tie.

if p1 in ROCK:
    if p2 in SCISSORS:
        winner = True
    elif p2 in PAPER:
        winner = False
elif p1 in PAPER:
    if p2 in ROCK:
        winner = True
    elif p2 in SCISSORS:
        winner = False
elif p1 in SCISSORS:
    if p2 in PAPER:
        winner = True
    elif p2 in ROCK:
        winner = False

if winner is None:
    print("Tie!")
elif winner:
    print("Player 1 wins!")
else:
    print("Player 2 wins!")

print(f"Player 1 chose: {p1} and Player 2 chose: {p2}")

"""This program converts a whole number input by the user to binary form"""

a = int(input("Enter a whole number: "))
bit = []

while int(a) > 0:
    bit.append(a % 2)
    a = int(a / 2)

bit.reverse()
for i in bit:
    print(i, end="")

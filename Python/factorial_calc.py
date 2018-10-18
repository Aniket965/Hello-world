"""Calculates factorial of a number input by the user"""

n = int(input("Enter a number to calculate factorial: "))
f=1
i=1
while i<=n:
   f*=i
   i+=1

print(str(n) + "! = " + str(f))

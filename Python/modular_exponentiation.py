#python 3.5.2

#This program takes three(3) integers(b,p,m) as input
#and outputs (b^p)%m.

#Naive approach to this problem would be to calculate
#b^p first and then calulate its % with m, but that
#wont work for large b and p because b^p will overflow.

#This program demonstrate pow function which uses
#modular exponentiation to calculate (b^p)%m where a,b,n 
#can be fairly large integer values.

print("This program takes 3 integers b,p,m as input and outputs (b^p)%m")
print("^ symbol is used to denote power and not XOR")
print("Enter the base (b)(integer)")
b = int(input())
print("Enter the power (p)(integer)")
p = int(input())
print("Enter the number by which mod is to be taken (m)(integer)")
m = int(input())
print("(b^p)%m = ",pow(b,p,m))

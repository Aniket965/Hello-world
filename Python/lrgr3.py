n1=int(input("Enter the first number:- "))
n2=int(input("Enter the second number:- "))
n3=int(input("Enter the third number:- "))
temp=n1
if n2>temp:
	temp=n2

if n3>temp:
	print(n3," is greater")
else: 
	print(temp," is greater")

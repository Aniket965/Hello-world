def GCD(num1, num2):
	if num2 is 0:
		return num1
	else:
		return GCD(num2,(num1%num2))

num1,num2=10,20
ans=GCD(num1,num2)
print("GCD of",num1,"&",num2,"is:",ans)

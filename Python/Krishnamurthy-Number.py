num= int(input("Enter any number"))
temp=num
rem=0

for i in range (num-1,1,-1):
	num=num*i
	
while(temp!=0):
	rem+=(temp%10)
	temp=temp//10
	
	
print (rem)
print(num)
if (num==rem):
	print("Is K number")
	
else :
	print("Not K number")

a=input("Enter any number to know the armstrong numbers before it:")
s=0
print("The armstrong numbers are")
for i in range(1,int(a)):
	b=i
	d=str(i)
	e=len(d)
	j=0
	while(j<e):
		f=int(d[j])**e
		s=s+f
		j=j+1
	if s==b:
		print(s)
		s=0
	else:
		s=0

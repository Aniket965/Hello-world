liste1=list()
liste2=list()
liste3=list()
for x in range(0,1001):
	if x%3==0 :
		liste1.append(x)
	if x%5==0 :
		liste2.append(x)
	if x%15==0 :
		liste3.append(x)



a=0
for x in liste1:
	a+=x
b=0
for x in liste2:
	b+=x
c=0
for x in liste3:
	c+=x
d=a+b-c
print(d)

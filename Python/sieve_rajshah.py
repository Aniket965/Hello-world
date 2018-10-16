from math import sqrt
n=int(input())
l=[1]*(n+1)
l[0]=0
l[1]=0
for i in range(2,sqrt(n+1)+1):
	if(l[i]==1):
		for j in range(i*i,n+1,i):
			if(l[j]==1):
				l[j]=0
print(*l)				

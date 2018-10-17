for _ in range(int(input())):
	n=int(input())
	a=list(map(int,input().split()))
	t=1
	p=a[0]
	ans=0
	while t<n:
		x=t
		t+=p
		for i in range(x,x+p):
			if i<n:
				p+=a[i]
		
		ans+=1
		#print(ans,t,p)
	print(ans)

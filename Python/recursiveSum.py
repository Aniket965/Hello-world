# Code to find sum of first N natural numbers
def recSum(n):
	if n==0:
		return 0
	return n+recSum(n-1)

n=int(input())
print(recSum(n))

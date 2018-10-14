def fib(n):
	f = [0, 1]
	for i in xrange(2, n + 1):
		f.append(f[-1] + f[-2])
	return f[n]
	
for i in xrange(1, 12):
	print fib(i)

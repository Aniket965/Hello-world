def isPowerOf2(n):
  return n & (n - 1) == 0
  
for i in xrange(1, 130):
  if isPowerOf2(i):
    print i

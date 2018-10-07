import sys
factorial = lambda w: reduce(lambda x,y: x*y, range(1,w+1)) if w > 0 else 1 if w == 0 else None
print(factorial(int(sys.argv[1])))

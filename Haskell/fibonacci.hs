--Naive approach
fib 0 = 0
fib 1 = 1
fib n = fib (n-1) + fib (n-2)

--Better
fib2 = 0 : 1 : zipWith (+) fib2 (tail fib2)

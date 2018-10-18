"""
10001st prime
Problem 7 
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
What is the 10 001st prime number?
"""
import timeit

def is_prime(number):
	if number <= 1:
		return False
	for i in range(2,number):
		if (number%i) == 0:
			return False
	return True

start = timeit.default_timer()
primes = list()
x = 2
while len(primes) < 10001:
	if is_prime(x):
		primes.append(x)
	x += 2
stop = timeit.default_timer()

print(primes[-1])
print(stop-start)

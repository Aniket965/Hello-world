"""
https://projecteuler.net/problem=4
Largest palindrome product
Problem 4 
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
Find the largest palindrome made from the product of two 3-digit numbers.
"""

def is_palindrome(number):
	number = str(number)
	if number == ''.join(reversed(number)):
		return True
	return False

p = 0
for x in range(100, 1000):
	for y in range(100, 1000):
		z = x*y
		isp = is_palindrome(z)
		print("{}x{}={} - {}".format(x,y,z,isp))
		if isp and z > p:
			p = z
print("Result: {}".format(p))

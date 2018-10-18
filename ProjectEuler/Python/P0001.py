"""
https://projecteuler.net/problem=1
Multiples of 3 and 5
Problem 1 
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9.
The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
"""
class Multiples(object):
	def __init__(self, below):
		self.multiples = tuple(i for i in range(1,below) if self.is_multiple(i))
		self.sum = sum(self.multiples)
	def is_multiple(self, number):
		if not bool(number%3) or not bool(number%5):
			return True
		return False

#Numbers below 10 multiples of 3 OR 5:
multiples = Multiples(10)
print("Numbers below 10 multiples of 3 OR 5:\n{}\nSum: {}".format(
	multiples.multiples,
	multiples.sum
))

#Numbers below 1000 multiples of 3 OR 5:
multiples = Multiples(1000)
print("Numbers below 1000 multiples of 3 OR 5:\n{}\nSum: {}".format(
	multiples.multiples,
	multiples.sum
))

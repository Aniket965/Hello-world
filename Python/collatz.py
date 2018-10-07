#!/usr/bin/env python3

#input number 
number = 1337.0

while number != 1:
	print(number)
	if number % 2 == 0:
		number /= 2
	else:
		number *= 3
		number += 1

print(1)
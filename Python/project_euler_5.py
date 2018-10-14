# https://projecteuler.net/ 
# Problem 5
# Smallest multiple
# 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
# What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

num = 2520
yeet = False
found = [False]*21
found[0] = True
while yeet is False:
    for i in range(1,21):
        if num%i != 0:
            break
        else:
            found[i] = True
    if False in found:
        num+=20
        found = [False]*21
        found[0] = True
    else: 
        yeet = True
        print(num)

'''
Write a function sumprimes(l) that takes as input a list of integers l and retuns the sum of all the prime numbers in l.

Here are some examples to show how your function should work.

  >>> sumprimes([3,3,1,13])
  19
'''

def sumprimes(l):
    prime_sum = int()
    for num in l:
        if is_prime(num):
            prime_sum = prime_sum + num
    return prime_sum


def is_prime(n):
    factor_list = []
    for num in range(2, n+1):
        if n % num == 0:
            factor_list = factor_list + [num]
    return len(factor_list) == 1
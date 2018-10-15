# -*- coding: utf-8 -*-
"""
Created on Tue Aug 14 21:19:08 2018

@author: Luis Palomino
"""

"""
    Works only when x and y are >= 0
"""
def karatsuba(x, y):
    if len(str(x)) == 1 or len(str(y)) == 1:
        return x * y
    
    n = max(len(str(x)),len(str(y)))
    n2 = n//2
    
    a = x // 10**(n2)
    b = x % 10**(n2)
    c = y // 10**(n2)
    d = y % 10**(n2)

    ac = karatsuba(a, c)
    bd = karatsuba(b, d)
    adbc = karatsuba(a+b,c+d) - ac - bd
    
    return pow(10, 2*n2)*ac + pow(10, n2)*adbc + bd
    

# Multiply two 64-bit integers
print(karatsuba(3141592653589793238462643383279502884197169399375105820974944592,2718281828459045235360287471352662497757247093699959574966967627))
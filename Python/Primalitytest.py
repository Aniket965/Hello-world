from math import sqrt

def isPrime(N):
    ''' A function which will tell u whether the number is prime or not in O(squareroot(N)) for every number'''
    square_root = int(sqrt(N))
    for i in range(2, square_root):
        if(N % i == 0):
            return False
    return True

N = int(input())  # enter the number
# calline the function
print(isPrime(N))

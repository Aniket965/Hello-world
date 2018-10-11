import math
prime_factors = []
prime_amount = []
def primeFactors(n):
    while n % 2 == 0:
        prime_factors.append(2)
        n = n / 2
    for i in range(3,int(math.sqrt(n))+1,2): 
        while n % i== 0:
            prime_factors.append(i)
            n = n / i
    if n > 2:
        prime_factors.append(n)

def primeCount(primes):
    counted = []
    for i in range(len(primes)):
        if primes[i] not in counted:
            counted.append(primes[i])
            prime_amount.append([primes[i], primes.count(primes[i])])

def amountOfDivisor(primes):
    count = 1
    for i in range(len(primes)):
        count *= (primes[i][1] + 1)
    return count

while True:
    print("Enter a natural number or -1 to terminate program")
    num = int(input())
    if num > 0:
        primeFactors(num)
        primeCount(prime_factors)
        divisors = amountOfDivisor(prime_amount)
        print("The prime factorization of " + str(num) )
        for i in range(len(prime_amount)):
            print(str(prime_amount[i][0]) + " to the power of " + str(prime_amount[i][1]))
        print(str(num) + " has a total of " + str(divisors) + " divisors including one and itself")
        prime_factors.clear()
        prime_amount.clear()
    else:
        print("The program will terminate")
        break

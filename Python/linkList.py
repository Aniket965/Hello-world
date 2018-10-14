
def find_primes_sieve(num):
    # list of all numbers upto n
    intList = [True for i in range(num+1)]

    # first prime
    p = 2

    while p * p <= num:

        # if intList[p] is True means its a prime number
        if intList[p]:
            for i in range(p**2, num+1, p):
                intList[i] = False

        p += 1

    lis = set()
    for i in range(2, len(intList)):
        if intList[i]:
            lis.add(i)

    return lis


def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)


n = int(input())

primes = find_primes_sieve(n)


if n in primes:
    print(len(primes))
else:
    count = 1

    for i in range(2, n):
        if n % i == 0:
            continue
        elif i in primes or gcd(i, n) == 1:
            count += 1
print(count)
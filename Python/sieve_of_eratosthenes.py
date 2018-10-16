def sieve_of_eratosthenes(num):
    
    prime = [True] * (num + 1)
    p = 2
    while (p * p <= num):
        # If prime[p] is not changed, then it is a prime
        if (prime[p] is True):
            # Update all multiples of p
            for i in range(p * p, num + 1, p):
                prime[i] = False
        p += 1
    # Print all prime numbers
    for p in range(2, num):
        if prime[p]:
            print(p)

def main():

    num = 30
    print("Following are the prime numbers smaller than "
            " or equal to {}: {}".format(num, sieve_of_eratosthenes(num)))


if __name__=='__main__':
    main()

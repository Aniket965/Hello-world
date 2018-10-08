class solution:
    def sieve(self, A):
        prime = [True for i in range(A+1)]
        p = 2
        
        at=list()
        while (p * p <= A):
             
            # If prime[p] is not changed, then it is a prime
            if (prime[p] == True):
                 
                # Update all multiples of p
                for i in range(p * 2, A+1, p):
                    prime[i] = False
            p += 1
         
        # Print all prime numbers
        for p in range(2, A):
            if prime[p]:
                at.append(p)
                
        return at
#function to check if no is prime
def ChkPrime(n):   
    prime = 1
    if(n==0):
        return 0
    if(n==2):
        return prime
    for i in range(2,(n//2) and prime==1):
        if(n%i==0):
            prime=0
    return prime

#to check if number is semi prime
if __name__ == '__main__':
    n = int(input())
    for i in range(n):
        if(ChkPrime(i)):
            if(n%i==0):
                m=n/i
                if(ChkPrime(m)):
                    SemiPrime=1
    if(SemiPrime==1):
        print("Semi prime")
    else:
        print("Not Semi prime")

def gcd(m, n):
    cf = 1
    if m > n:
        cf = gcd(n, m)
    else:
        for i in range(1, m+1):
            if m % i == 0 and n % i == 0:
                cf = i
    return cf
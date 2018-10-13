def lcm(m, n):
    cf = 1
    if m > n:
        cf = lcm(n, m)
    else:
        for i in range(1, m+1):
            if m % i == 0 and n % i == 0:
                cf = i
    return (m*n)/cf

#! /usr/bin/python
# -*- coding: utf-8 -*-


def is_prime(n):
    if (n == 2) or (n == 3):
        return True
    if (n < 2) or (n %2 == 0):
        return False
    if n < 9:
        return True
    if n % 3 == 0:
        return False
    sqrt_n = int(n ** 0.5)
    step = 5
    # 😇
    while step <= sqrt_n:
        if n % step == 0:
            return False
        if n % (step + 2) == 0:
            return False
        step += 6
    return True


def is_circular_prime(n):
    num = str(n)
    for i in range(len(num)):
        if not is_prime(int(num[i:] + num[:i])):
            return False
    return True

if __name__ == '__main__':
    num = int(input())
    result = (sum(1 for n in range(2, num) if is_circular_prime(n)))
    print(result)

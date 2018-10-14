#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Apr 28 19:35:41 2018

@author: ska

GCDDIV
"""
def pfac(n):
    ar =[]
    if n%2 == 0:
        ar.append(2)
    while n%2 ==0:
        n //= 2
    for i in range(3, int(math.sqrt(n))+1,2):
        if n%i == 0:
            ar.append(i)
        while n%i == 0:
            n //= i
    if n>2:
        ar.append(n)
    return ar
            
import math
for _ in range(int(input())):
    n,k = map(int, input().split())
    ar = list(map(int, input().split()))
    if n==1:
        print("YES")
    else:
        g = math.gcd(ar[0],ar[1])
        for i in range(2,n):
            g = math.gcd(g,ar[i])
        if g<= k:
            print('YES')
        else:
            gar = pfac(g)
            flag =1
            for i in range(len(gar)):
                if gar[i] > k:
                    flag =0
                    break
            if flag ==1:
                print('YES')
            else:
                print('NO')
            
        

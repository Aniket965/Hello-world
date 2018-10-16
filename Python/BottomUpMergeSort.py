# -*- coding: utf-8 -*-
"""
Created on Mon Sep  3 10:37:40 2018

@author: Luis Palomino
"""

def mergeRevse(x):
    n = len(x)
    inc = 2
    def merge(A, B):
        C = [None]*(len(A)+len(B))
        i, j, k = 0, 0, 0
        while i < len(A) and j < len(B):
            if A[i] < B[j]:
                C[k] = A[i]
                i+=1
            else:
                C[k] = B[j]
                j+=1
            k+=1
        
        while i < len(A):
            C[k] = A[i]
            i+=1
            k+=1
        while j < len(B):
            C[k] = B[j]
            j+=1
            k+=1
            
        return C
    while True:
        repet = 0
        for i in range(0, n, inc):
            repet+=1
            lim1 = (i + i+inc)//2
            lim2 = i+inc
            if x[lim1:lim2] == []:
                C = merge(x[i:lim1], [])    
            else:
                C = merge(x[i:lim1], x[lim1:lim2])
            cont = 0
            for j in range(i, lim2):
                if j >= n:
                    break
                x[j] = C[cont]
                cont+=1
        if repet <= 1:
            break
        inc*=2


x = [5,1,0,3,4,56,70,34,203,0,-100,10,102,11,43,23,4,1]
mergeRevse(x)
print(x)
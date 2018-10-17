# -*- coding: utf-8 -*-
"""
Created on Sun Sep  2 15:58:58 2018

@author: Karan Randhir
"""
#Print factorial of a number input by user 
n=input("Enter number ")
try :
    n=int(n)
    print("Enter an intege")
    
    fact = 1
    for i in range (1,n+1) : 
        fact = fact *i
    print("Factorial of the number is",fact)
except :
    print("please enter an integer")
    
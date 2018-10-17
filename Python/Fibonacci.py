# -*- coding: utf-8 -*-
"""
Created on Sun Sep  2 15:13:33 2018

@author: Karan Randhir
"""
#Print fibonacci series upto a range input by user
first = 0 
second = 1
n=input("Enter the range of fibbonaci series")
try :
    n=int(n)

    print("Required fibonacci series is ")    
    for i in range (0,n) :
        if i <=1 :
            fibonacci = i 
        else :
            fibonacci = first + second 
            first = second 
            second = fibonacci 
        print(fibonacci)    
except :
    print("please enter an integer")    
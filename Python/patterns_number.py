# -*- coding: utf-8 -*-
"""
Created on Mon Oct 15 14:52:48 2018

@author: stuti.verma
"""

#Printing patterns   
#Pattern 1
for i in range(0,7,1):
    s = "" 
    for j in range(0,i,1):
        s+=str(i)
        #print(' %d'%i)
    print(s)
    

#Pattern 2    
multiplicationFactor=0
N=7
for i in range(1,N,1):
    s = "" 
    spaceStr=""
    for j in range(0,i+multiplicationFactor,1):
        s += str(i)
        #print(' %d'%i)
    for spaces in range(0,N-multiplicationFactor,1):
        spaceStr += " "
    print(spaceStr+s)    
    multiplicationFactor +=1    
    

#Pattern 3    
multiplicationFactor=0
divisionFactor=0
N=7
count=1
for i in range(1,(2*N),1):
    s = "" 
    spaceStr=""
    for j in range(0,i+multiplicationFactor,1):
        s += str(count)

    for spaces in range(0,N-multiplicationFactor,1):
        spaceStr += " "
  
    
    if i<N:
        multiplicationFactor +=1
        divisionFactor=0
        count +=1
    elif i==N:
        multiplicationFactor -=1
        divisionFactor +=0
        count -=1
    else:
        multiplicationFactor -=1
        divisionFactor +=2
        count -=1
        s=s[:-(divisionFactor)]
        
    print(spaceStr+s)     
    
    
    
    
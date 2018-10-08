import numpy as np
import os

def dot_product(a,b):
    return(a[0]*b[0]+a[1]*b[1]+a[2]*b[2])


a=np.zeros(3)
b=np.zeros(3)
for i in range(3):
    a[i]=int(input("write the"+str(i)+"element of a"))
    b[i]=int(input("write the"+str(i)+"element of b"))
print("The vectors are\n",a,"\n",b)
print("Dot Product is", dot_product(a,b))


import numpy as np
import os
import math

def dot_product(a,b):
    return(a[0]*b[0]+a[1]*b[1]+a[2]*b[2])

def angle(a,b):
    dot=dot_product(a,b)
    mag_a=(a[0]**2+a[1]**2+a[2]**2)**0.5
    mag_b=(b[0]**2+b[1]**2+b[2]**2)**0.5
    return math.acos(dot/(mag_a*mag_b))
a=np.zeros(3)
b=np.zeros(3)
print("Use Rectangular Coordinats x, y and z")
for i in range(3):
    a[i]=int(input("write the"+str(i)+"element of a"))
    b[i]=int(input("write the"+str(i)+"element of b"))
print("The vectors are\n",a,"\n",b)
print("Dot Product is", dot_product(a,b))
print("Angle between two vectors is (in radians)", angle(a,b), "and in degrees",(180/math.pi)*angle(a,b))

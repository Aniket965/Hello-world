from math import sqrt
x1=int(input("Enter x1"))
y1=int(input("Enter y1"))
x2=int(input("Enter x2"))
y2=int(input("enter y2"))
c1=input("enter 1st city")
c2=input("enter 2nd city")
c3=c1[0:4]+c2[-4:]
dist=sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
print("the distance ",c3,"is",dist)

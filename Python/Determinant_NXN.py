import numpy
d=int(input())
l=[]
for i in range(d):
    l.append(list(map(float,input().split())))
print(numpy.linalg.det(l))

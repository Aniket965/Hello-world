import sys
l1=[]
l2=[]
l1=map(int,sys.stdin.readline().split())
from collections import OrderedDict
l2=list(OrderedDict((x,True) for x in l1).keys())
for i in l2:
  print(i,end=" ")

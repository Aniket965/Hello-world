num=1
numMostrato=1
while(True):
    if num > 1:
        for i in range(2,num):
           if (num % i) == 0:
               break
           else:
               if(num != numMostrato):
                   print(num)
                   numMostrato=num
    num=num+1

def addpoly(x,y):
    i=j=0
    res=[]
    while i<len(x) and j<len(y):
       if x[i][1]==y[j][1]  and x[i][0]+y[j][0]!=0:
           res=res+[(x[i][0]+y[j][0],x[i][1])]
           i+=1
           j+=1
           #print(res)
       elif x[i][1]==y[j][1] and x[i][0]+y[j][0]==0:
           i+=1
           j+=1
       elif x[i][1]>y[j][1]:
           res=res+[x[i]]
           i+=1
           #print(i,j)
           #print(res)
       elif x[i][1]<y[j][1]:     
           res=res+[y[j]]
           j+=1
           #print(i,j)
           #print(res)
    if i<len(x):
         res=res+x[i:]
         #print(res)
    elif j<len(y):
         res=res+y[j:]
         #print(res)
    return(res)

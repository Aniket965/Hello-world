def apply(i,x,y,z):
    while(z[i]>=0 and y[i]==-1):
        if(x.count(z[i])!=0):
            y[i]=z[i]
            x.remove(z[i])
        else:
            z[i]-=1
            z[i+1]=9
    if(y[i]==-1):
        return 0
    else:
        while(z[i+1]>=0 and y[i+1]==-1):
            if(x.count(z[i+1])!=0):
                y[i+1]=z[i+1]
                x.remove(z[i+1])
            else:
                z[i+1]-=1
        if(y[i+1]==-1):
            return 0
        else:
            return 1
x=list(map(int,input().split(',')))
y=[-1,-1,-1,-1,-1,-1]
if(x.count(2)>0 and x.count(4)>0 and x.count(0)>=4):
    print("24:00:00")
else:
    z=[2,3,5,9,5,9]
    i=0
    flag=0
    while(i<6):
        p=apply(i,x,y,z)
        if(p==1):
            i+=2
        else:
            print("impossible")
            flag=1
            break
    if(flag==0):
         print(y[0],end='')
         print(y[1],end=':')
         print(y[2],end='')
         print(y[3],end=':')
         print(y[4],end='')
         print(y[5],end='')
                            
                            
                            
                            
            
                           
                        
                        




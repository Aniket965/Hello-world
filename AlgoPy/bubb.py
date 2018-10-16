def bubble():
    a=[1,2,5,7,9,0,3]
           
    k=0
    while k<=len(a):
        for j in range(0 , len(a)-1):
            b=a[j]
            c=a[j+1]
                
            if a[j]>a[j+1]:
                a[j]=c
                a[j+1]=b
        k=k+1
    return a
print(bubble())


def selection():
    
    b=[1,7,5,6,9,10,0,-1]
    for i in range(0,len(b)-1):
        
        mi=i
        for j in range(i+1 , len(b)):
            
            if b[j]<b[mi]:
                mi=j
        b[i],b[mi]=b[mi],b[i]
                
            
                
    return b
print(selection())

def insertion():
    c=[1,7,9,6,3,4,8,4,5]
    for i in range(1 ,len(c)):
        for j in range(0,len(c)-1):
            if c[i]<c[j]:
                c[i],c[j]=c[j],c[i]
    return c
print(insertion())


 

            
            
        

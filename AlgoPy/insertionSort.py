
A = [2,7,4,1,5,3,0]

for j in range(1,len(A)):
    i = j
    while(A[i-1]> A[i]):
        A[i-1],A[i] = A[i],A[i-1]
        if(i-1 !=0):
            i-=1
print(A)
        

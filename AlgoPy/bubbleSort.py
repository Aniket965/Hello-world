
A = [2,7,4,1,5,3]

for j in range(1,len(A)):
    swapped = False
    for i in range(1,len(A)):
        if(A[i] < A[i-1]):
            A[i-1],A[i] = A[i],A[i-1]
            swapped = True
    if(not swapped): 
        break
print(A)
        

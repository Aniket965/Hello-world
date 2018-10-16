
A = [2,7,4,1,5,3]
n = len(A)
for j in range(1,n):
    swapped = False
    for i in range(1,n):
        if(A[i] < A[i-1]):
            A[i-1],A[i] = A[i],A[i-1]
            swapped = True
    if(not swapped): 
        break
print(A)
        

def merge(L,R,A):
    nL = len(L) 
    nR = len(R)
    i = 0
    j = 0
    k = 0 
    while(i < nL and j < nR):
        if(L[i] <= R[j]):
            A[k] = L[i]
            i += 1
            k += 1
        else:
            A[k] = R[j]
            j += 1
            k += 1
    while(i<nL):
        A[k] = L[i]
        i += 1
        k += 1
    while(j<nR):
        A[k] = R[j]
        j += 1
        k += 1

def sort(A):
    if(len(A) < 2):
        return
    mid = len(A) // 2
    left = []
    right = []
    for i in range(0,mid):
        left.append(A[i])
    for i in range(mid,len(A)):
        right.append(A[i])
    sort(left)
    sort(right)
    merge(left,right,A)


A = [2,4,1,6,8,5,3,7]
sort(A)
print(A)

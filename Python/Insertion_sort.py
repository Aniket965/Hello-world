def insertionSortRecursive(arr,n): 
    if n<=1: 
        return
      
    # Sort first n-1 elements 
    insertionSortRecursive(arr,n-1) 
    '''Insert last element at its correct position  in sorted array.'''
    last = arr[n-1] 
    j = n-2
       
    while (j>=0 and arr[j]>last): 
        arr[j+1] = arr[j] 
        j = j-1
  
    arr[j+1]=last 
      
# A utility function to print an array of size n 
def printArray(arr,n): 
    for i in range(n): 
        print(arr[i])
  

array = [12,11,13,5,6] 
n = len(array) 
insertionSortRecursive(array, n) 
printArray(array, n) 
  
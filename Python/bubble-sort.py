
def bubbleSort(arr): 
    n = len(arr) 
  
    # Traverse through all  elements 
    for i in range(n): 
  
         
        for j in range(0, n-i-1): 
  
            
            # Swap if the element found is greater 
            # than the next element 
            if arr[j] > arr[j+1] : 
                arr[j], arr[j+1] = arr[j+1], arr[j] 

def bubbleSort(arr):
    n = len(arr)
 
    # Traverse through all array elements
    for i in range(n):
 
        # Last i elements are already in place
        for j in range(0, n-i-1):
 
            # traverse the array from 0 to n-i-1
            # Swap if the element found is greater
            # than the next element
            if arr[j] > arr[j+1] :
                arr[j], arr[j+1] = arr[j+1], arr[j]
 
# Driver code to test above
arr = []
num1 = int(input('enter the value\n'))
num2 = int(input('enter the value\n'))
num3 = int(input('enter the value\n'))
num4 = int(input('enter the value\n'))
num5 = int(input('enter the value\n'))

#For putting the values in list arr:-
arr.append(num1)
arr.append(num2)
arr.append(num3)
arr.append(num4)
arr.append(num5)

 
bubbleSort(arr)
 
print ("Sorted array is:")
for i in range(len(arr)):
    print ("%d" %arr[i]), 


#Bubble Sort in Python 3.x

#Function to swap indices a and b in list arr

def swap(arr, a, b):
    x = arr[a]
    arr[a] = arr[b]
    arr[b] = x
    
# Function that performs bubble sort

def bubble_sort(li):
	for i in range(len(li)-1):
		for j in range(len(li)-i-1):
			if(li[j]>li[j+1]):
				swap(li, j, j+1)


	return li
    
    
    
# To check the functioning of the above function :

# 1) Uncomment the next lines
#lis = [2,9,4,1,6,5,-1]
#print(bubble_sort(lis))

# 2) Take input from the user, uncomment the following lines to run
#print("Please enter the list of numbers you want to sort")
#a = [int(x) for x in input().split()]
#print(bubble_sort(list(a)))


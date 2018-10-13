import random

# Function for bubble sorting an array of number
def bubbleSort(array_of_number):
    array_len = len(array_of_number)

    for i in range(array_len):

        for j in range(0, array_len - i - 1):
            
            if array_of_number[j] > array_of_number[j + 1] :
                # Check if all numbers are int
                if (isinstance(array_of_number[j], int) != True \
                    or isinstance(array_of_number[j + 1], int) != True):
                    print('Error: Array is not int')
                    return
                else:
                    array_of_number[j], array_of_number[j + 1] = array_of_number[j + 1], array_of_number[j]


if __name__ == "__main__":
    lists = random.sample(range(0, 301), 300)
    print ("Unsorted list:", lists)
    print ()
    bubbleSort(lists)
    print ("Sorted list: ", lists)

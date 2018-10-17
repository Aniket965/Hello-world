# Given a sorted list and an input number as inputs, write a function to return a Range object,
#  consisting of the indices of the first and last occurrences of the input number in the list. 

# Note: The List can have duplicate numbers. The indices within the Range object should be zero based.



# The following solution is in O(n) time. A better solution would be in O(logn) time. It's best to try and get to O(logn) any time searching is involved.
def find_range(input_list,input_number):
    
    if input_number in input_list:
        return Range(input_list.index(input_number), len(input_list) - 1 - input_list[::-1].index(input_number))
    else:
        return Range()

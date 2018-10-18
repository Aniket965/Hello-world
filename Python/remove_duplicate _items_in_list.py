# Remove duplicate items in a list
def remove_duplicates(list_with_duplicates): 
    corrected_list = [] 
    for num in list_with_duplicates: 
        if num not in corrected_list: 
            corrected_list.append(num) 
    return corrected_list

# Test function
old_list = [1,2,3,3,4]
new_list = remove_duplicates(old_list)

print(new_list)

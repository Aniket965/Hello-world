def areRotations(string1, string2): 
    size1 = len(string1) 
    size2 = len(string2) 
    temp = '' 
  
    # Check if sizes of two strings are same 
    if size1 != size2: 
        return 0
  
    # Create a temp string with value str1.str1 
    temp = string1 + string1 
  
    # Now check if str2 is a substring of temp 
    # string.count returns the number of occurences of 
    # the second string in temp 
    if (temp.count(string2)> 0): 
        return 1
    else: 
        return 0

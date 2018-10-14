def areAnagram(str1, str2): 
    # Create two count arrays and initialize all values as 0 
    count1 = [0] * NO_OF_CHARS 
    count2 = [0] * NO_OF_CHARS 
    # For each character in input strings, increment count 
    # in the corresponding count array 
    for i in str1: 
        count1[ord(i)]+=1
    for i in str2: 
        count2[ord(i)]+=1
    # If both strings are of different length. Removing this 
    # condition will make the program fail for strings like 
    # "aaca" and "aca" 
    if len(str1) != len(str2): 
        return 0
    # Compare count arrays 
    for i in xrange(NO_OF_CHARS): 
        if count1[i] != count2[i]: 
            return 0
    return 1

"""Function that returns length of a string"""

def lengthofstring(string):
    length = []
    for i in string:
        length.append(i)
    x = string.index(string[-1])
    return x+1

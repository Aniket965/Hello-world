"""This function gives length of a string without using predefined len function"""

def lengthofstring(string):
    length = []
    for i in string:
        length.append(i)
    x = string.index(string[-1])
    return x+1

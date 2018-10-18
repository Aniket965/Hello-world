# -*- coding: utf-8 -*-
#program to  replace spaces in a string with a '-'
def replace(string):
    string=string.split(" ")
    string="-".join(string)
    return string
S=input("Enter a string:  ")
N=replace(S)
print ("The new string is",'\n',N)
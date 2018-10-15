#Problem :
# You have been given an array A of size N consisting of positive integers. You need to find and print the product of all the number in this array Modulo 10^9+7.
# 
# Input Format:
# The first line contains a single integer N denoting the size of the array. The next line contains N space separated integers denoting the elements of the array
# 
# Output Format:
# Print a single integer denoting the product of all the elements of the array Modulo 10^9+7.
#Hackerearth>Basic Programming>Input/Output>Basics of Input/Output> Find Product
#in Python 2.7

#Solution:
size =input()
n =raw_input().split()
answer=1
for i in range (0,size):
        answer=(answer*int(n[i]))%(10**9 + 7)
print(answer)    


/*
created by: Keshav Gupta
7:27 PM
*/

# method to calculate factorial

def Facto(t):
  i=1
  for x in range(1,t+1):
    i=i*x
  print("factorial of ",t," is ",i)
  
# main method

print("Enter the nu,ber to find factorial")
t=int(input())
Facto(t)


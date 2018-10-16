# Python Program to find the L.C.M. of two input number

# define a function
def lcm(x, y):

   # choose the greater number
   if x > y:
       greater = x
   else:
       greater = y

   while True:
       if((greater % x == 0) and (greater % y == 0)):
           lcm = greater
           break
       greater += 1

   return lcm


# take input from the user
num1 = int(input("Enter first number: "))
num2 = int(input("Enter second number: "))

print("The L.C.M. of", num1,"and", num2,"is", lcm(num1, num2))

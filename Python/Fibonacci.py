# Fibunacci numbers
# 
fibonacci = [1, 1] # initialize the fibonacci vector
print("How much numbers shall be calculated?:")
n = int(input()) # read value
while len(fibonacci) < n: # loop until the requested nr is calculated
    fibonacci.append(fibonacci[-1] + fibonacci[-2]) # calculate the next fibonacci nr and add to the array
# print all calculated numbers
for i in range(n):
    print(fibonacci[i], end=' ')

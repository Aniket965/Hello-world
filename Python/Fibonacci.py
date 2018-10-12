#Doesn't work.
import time

fibonacci = [1, 1]
n = int(input())
while len(fibonacci) < n:
    fibonacci.append(fibonacci[-1] + fibonacci[-2])
for i in range(n):
    print(fibonacci[i], end=' ')

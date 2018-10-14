fibonacci = [0, 1]
n = int(input("Enter a number: "))
while len(fibonacci) < n:
    fibonacci.append(fibonacci[-1] + fibonacci[-2])
for i in range(n):
    print(i + 1, ":", fibonacci[i])

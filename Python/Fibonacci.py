
fibonacci = [0, 1] #initialising base case
n = int(input("Enter a number: ")) #accepting input in Variable n
while len(fibonacci) < n:
    fibonacci.append(fibonacci[-1] + fibonacci[-2]) # recurssion function of fibo[n-1= + fibo[n-2] = fibop[n]
for i in range(n):
    print(i + 1, ":", fibonacci[i]) #print fibonacci

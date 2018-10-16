number = int(input())
fact = 1
counter = 0
for i in range(1, number+1):
    fact  = fact*i
    if fact%10 == 0:
        counter += 1
        fact = fact // 10
print(counter)

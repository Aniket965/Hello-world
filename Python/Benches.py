n = int(raw_input())
m = int(raw_input())

a = []

for x in range(0, n):
    a.append(int(raw_input()))

maximum = max(a) + m

while m:
    a[a.index(min(a))] += 1
    m -= 1

print max(a), maximum

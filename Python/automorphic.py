num = int(input())
c = len(str(num))
sq = num * num
dig = sq % pow(10, c)

if dig == num:
    print("Automorphic")
else:
    print("Not automorphic")

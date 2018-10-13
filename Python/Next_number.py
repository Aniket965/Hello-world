def nxt(l):
    l[-1]+=1
    l.insert(0,0)
    if(l[-1]>9):
        l.pop(-1)
        return(nxt(l)+[0])
    else:
        for i in range(len(l)):
            if l[0]==0:
                l.pop(0)
                continue
            else:
                break
        return l

a = input("Enter number with each digit as one element of a list")

b = nxt(a)

print(b)

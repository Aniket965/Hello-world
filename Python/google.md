# Thoughts
After closely examinated the equation: ```WWWDOT = GOOGLE + DOTCOM```, we can find that there are only 9 variables : G, D, O, W, T, M, C, L, E. By trying all the possible combations we will certainly find out all the possible solutions.

# PseudouCode

# Python Realization
```python
import itertools
mylist = [0, 1, 2, 3, 4, 5, 6, 7, 8] # representing G, D, O, W, T, M, C, L, E respectively
Plist = list(itertools.permutations('0123456789', 9)) # return all the possible combations
for i in range(3628800):
    mylist = Plist[i]
    if mylist[0] in ['0'] or mylist[1] in ['0'] or mylist[3] in ['0']:
        continue
    google = eval(mylist[0]) * 100100 + eval(mylist[2]) * 11000 + eval(mylist[7]) * 10 + eval(mylist[8])
    dotcom = eval(mylist[1]) * 100000 + eval(mylist[2]) * 10010 + eval(mylist[4]) * 1000 + eval(mylist[6]) * 100 + eval(mylist[5])
    wwwdot = eval(mylist[3]) * 111000 + eval(mylist[1]) * 100 + eval(mylist[2]) * 10 + eval(mylist[4])
    if google + dotcom == wwwdot:
        print(google,'+',dotcom,'=',wwwdot)

```

# OutPuts
```
188106 + 589483 = 777589
188103 + 589486 = 777589
```

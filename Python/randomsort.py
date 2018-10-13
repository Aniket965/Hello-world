from random import randint

list_1 = list()

n = int(input('Enter number of digits to sort: '))
temp = 0
while n > 0:
    list_1.append(int(input('Enter Digit: ')))
    n = n - 1

sorted = False
while sorted == False:
    for x in range(len(list_1)):
        if x == len(list_1) - 1:
            sorted = True
            break
        if list_1[x] < list_1[x+1]:
            continue
        else:
            sorted = False
            break
    if sorted == True:
        break
    else:
        i = randint(0, len(list_1) - 1)
        j = randint(0, len(list_1) - 1)
        if list_1[i] < list_1[j]:
            temp = list_1[i]
            list_1[i] = list_1[j]
            list_1[j] = temp
print('Sorted: ', ' '.join(str(e) for e in list_1))

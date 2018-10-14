from random import randint

def is_sorted(list):
    for i in range(len(list)-1):
        if list[i] > list[i+1]:
            return False
    return True

def shuffle(list):
    for i in range(len(list)):
        r = randint(0, len(list)-1)
        list[i], list[r] = list[r], list[i]


list = [1, 5, 2, 0, 10]

print("Unsorted: ", list)

while not is_sorted(list):
    shuffle(list)

print("Sorted:   ", list)
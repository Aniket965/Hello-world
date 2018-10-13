import random

def bubbleSort(lists):
        for j in range(0, len(lists)-1-i):
            if(lists[j]>lists[j+1]):
                lists[j+1], lists[j] = lists[j], lists[j+1]
                
lists = random.sample(range(0, 5001), 5000)
print(lists)

bubbleSort(lists)

print(lists)

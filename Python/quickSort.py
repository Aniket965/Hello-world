import random

def quickSort(lists, p, r):
    if p < r:
        q = partition(lists, p, r)
        quickSort(lists, p, q-1)
        quickSort(lists, q+1, r)
        
def partition(lists, p, r):
    x = lists[r]
    i = p - 1
    for j in range(p, r):
        if lists[j]<=x:
            i = i + 1
            aux = lists[i]
            lists[i] = lists[j]
            lists[j] = aux
    aux = lists[i+1]
    lists[i+1] = lists[r]
    lists[r] = aux
    return i+1 
 
lists = random.sample(range(0, 5001), 5000)
print(lists)
quickSort(lists)
print(lists) 
    

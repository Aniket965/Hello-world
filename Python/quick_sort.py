def partition(a, low, high):
    piviot = a[high]
    i = low - 1
    for j in range(low, high):
        if a[j] <= piviot:
            i += 1
            a[j], a[i] = a[i], a[j]

    a[i+1], a[high] = a[high], a[i+1]

    return i + 1


def quick_sort(a, low, high):
    if low < high:
        pi = partition(a, low, high)
        quick_sort(a, low, pi-1)
        quick_sort(a, pi+1, high)


le = int(input("Enter the length of the array:"))
arr = []

for p in range(le):
    q = int(input())
    arr.append(q)

quick_sort(arr, 0, le - 1)

print("sorted array")
for t in range(le):
    print(arr[t])

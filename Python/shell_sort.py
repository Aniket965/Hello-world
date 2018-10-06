def shellSort(arr):
    n = len(arr)
    gap = int(n/2)


    while(gap > 0):

        for i in range(gap,n):
            temp = arr[i]
            j = i
            while(j >= gap and arr[j-gap] > temp):
                arr[j] = arr[j-gap]
                j = j-gap

            arr[j] = temp
        gap = int(gap/2)

arr = []
for i in range(0,5):
    b = int(input())
    arr.append(b)

shellSort(arr)

print(arr)

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

test_arr = [5,6,2,1,4,3,0]

shellSort(test_arr)

print(test_arr)

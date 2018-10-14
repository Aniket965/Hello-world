
def shell_sort(arr):
    """
    Fuction to sort using Shell Sort
    <https://en.wikipedia.org/wiki/Shellsort>.
    :param arr:     A list of element to sort
    """

    gap = int((len(arr)/2))
    while gap > 0:
        for i in range(gap, len(arr)):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j-gap]
                j -= gap

            arr[j] = temp

        gap /= 2
        gap = int(gap)

    return arr


def main():
    arr = [15, 12, 36, 63, 96]
    sorted_arr = shell_sort(arr)
    print('Sorted element using Shell Sort: {}'.format(
              ' '.join(map(str, shell_sort(arr)))))


if __name__ == '__main__':
    main()


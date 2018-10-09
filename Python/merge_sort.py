"""Merge sort implementation in python."""


def merge_sort(array):
    """Use merge sort to sort an array."""
    if(len(array)) > 1:
        mid = len(array) // 2

        left_array = array[:mid]
        right_array = array[mid:]

        merge_sort(left_array)
        merge_sort(right_array)

        # merge(left_array=left_array, right_array=right_array)
        i = j = k = 0
        while i < len(left_array) and j < len(right_array):
            if left_array[i] <= right_array[j]:
                array[k] = left_array[i]
                i += 1
            else:
                array[k] = right_array[j]
                j += 1
            k += 1

        while i < len(left_array):
            array[k] = left_array[i]
            i += 1
            k += 1

        while j < len(right_array):
            array[k] = right_array[j]
            j += 1
            k += 1

        return array


def main():
    """Run main function."""
    input = [i for i in range(10, 0, -1)]
    print(merge_sort(input))


if __name__ == "__main__":
    main()

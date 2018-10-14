#include <stdlib.h>
#include <stdio.h>

int is_sorted(int *arr, int num_elems)
{
    for (int i = 0; i < num_elems - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            return 0;
    }
    return 1;
}

void shuffle(int *arr, int num_elems)
{
    for (int i = 0; i < num_elems; i++)
    {
        int val = arr[i];
        int rand_ind = rand() % num_elems;
        arr[i] = arr[rand_ind];
        arr[rand_ind] = val;
    }
}

void print_arr(int *arr, int num_elems) 
{
    for (int i = 0; i < num_elems; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int numbers[] = {1, 10, 9, 7, 3, 0};

    printf("Unsorted: ");
    print_arr(numbers, sizeof(numbers)/sizeof(numbers[0]));

    while(!is_sorted(numbers, sizeof(numbers)/sizeof(numbers[0])))
        shuffle(numbers, sizeof(numbers)/sizeof(numbers[0]));

    printf("Sorted: ");
    print_arr(numbers, sizeof(numbers)/sizeof(numbers[0]));    

    return 0;
}
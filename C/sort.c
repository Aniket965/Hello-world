#include<stdio.h> 
  
void swap(int* a, int* b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
  
void quickSort(int arr[], int low, int high) 
{
    if (low >= high) return ; 
    int pivot = arr[(low + high)/2];
    int i = low;
    int j = high;

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }
    
    if (low < j) quickSort(arr, low, j); 
    if (i < high) quickSort(arr, i, high); 
}

void selectionSort(int arr[], int n)
{
    int i, j;
    for (i=0; i<n; i++)
        for (j=i+1; j<n; j++)
            if (arr[i] > arr[j]) swap(&arr[i], &arr[j]);
}

void insertionSort(int arr[], int n)
{
    int i, j, temp;
    for (i=1; i<n; i++) {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}
  
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
  
int main() 
{ 
    int arr1[] = {10, 7, 8, 9, 1, 5}; 
    int n1 = sizeof(arr1)/sizeof(arr1[0]); 
    quickSort(arr1, 0, n1-1); 
    printf("Quick sort: "); 
    printArray(arr1, n1);

    int arr2[] = {10, 7, 8, 9, 1, 5};
    int n2 = sizeof(arr2)/sizeof(arr2[0]); 
    selectionSort(arr2, n2);
    printf("Selection sort: "); 
    printArray(arr2, n2);

    int arr3[] = {10, 7, 8, 9, 1, 5};
    int n3 = sizeof(arr3)/sizeof(arr3[0]); 
    insertionSort(arr3, n3);
    printf("Insertion sort: "); 
    printArray(arr3, n3);

    return 0; 
} 


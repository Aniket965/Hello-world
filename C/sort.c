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

    return 0; 
} 


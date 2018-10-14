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
  
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
  
int main() 
{ 
    //Sample: int arr[] = {10, 7, 8, 9, 1, 5}; 
    int arr[] = { }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    quickSort(arr, 0, n-1); 
    printf("Sorted array: \n"); 
    printArray(arr, n); 
    return 0; 
} 


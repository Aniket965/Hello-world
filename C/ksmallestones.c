/*K smallest ones using partitioning algorithm and quicksort
input: an array of numbers and how many smallest numbers do user want( 1 5 6 -2 3 4    2)
output: the smallest numbers(-2 1)

*/

#include<stdio.h>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    
    int i = (low - 1);  
 
    for (int j = low; j <= high- 1; j++)
    {

        if (arr[j] <= pivot)
        {
            i++;    
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        
        int pi = partition(arr, low, high);
 
        
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void result(int a[],int n,int m)
{
    int i;
    quickSort(a,0,n-1);
    printf("The %d smallest one numbers are\n");
    for(i=0;i<m;i++)
    {
        printf("%d ",a[i]);
    }


}
int main()
{
    int n,i,m;
    printf("how many numbers do you want to take? \n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
       scanf("%d",&a[i]);
    }
    printf("how many minimum numbers do you want to take?\n");
    scanf("%d",&m);
    result(a,n,m);
    return 0;
}
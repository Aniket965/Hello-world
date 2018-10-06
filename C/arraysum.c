#include <stdio.h>

int main(){

    // Sum and Average of elements of the array
    int arr[10],i=0,sum=0,size=0,avg=0;

    printf("Enter size of array ");
    scanf("%d",&size);
    printf("\nEnter %d elements in the array \n");

    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
        sum = sum + arr[i];
    }
    avg=sum/size;

    printf("Sum of all the elements of the array is %d\nAverage of all the elements of the array is %d",sum,avg);
    
    printf("\n");
    return 0;
}
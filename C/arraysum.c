#include <stdio.h>

int main(){

    // Sum and Average of elements of the array
    long arr[100],i,sum=0,size;
    float avg;

    printf("Enter size of array ");
    scanf("%ld",&size);
    printf("\nEnter %ld elements in the array \n",size);

    for(i=0;i<size;i++)
    {
        scanf("%ld",&arr[i]);
        sum += arr[i];
    }
    avg=sum/size;

    printf("Sum of all the elements of the array is %ld\nAverage of all the elements of the array is %0.2f",sum,avg);
    
    printf("\n");
    return 0;
}

#include <stdio.h>

int main(){
    // Find Maximum element in an array
    int arr[10];
    int i=0,max=0,size=0;

    printf("Enter the size of the array ");
    scanf("%d",&size);

    printf("Enter %d elements in the array\n",size);
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }

    for(i=0;i<size;i++)
    {
        if(max<arr[i])
        {
            max= arr[i];
        }        
    }

    printf("Maximum value in the array is %d",max);


    printf("\n");
    return 0;
}
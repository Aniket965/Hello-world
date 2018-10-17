#include <stdio.h>

void main(){
    // Find Maximum element in an array
    int arr[100];
    int size,max,i,j;
    printf("Enter the size of the array:  ");
    scanf("%d",&size);
    printf("Enter %d elements in the array:\n",size);
    for(i=1;i<=size;i++)
    {
        scanf("%d",&arr[i]);
    }
    max=arr[0];
     for(i=1;i<=size;i++)
      {
        if(arr[i]>max)
          {
            max=arr[i];
            j=i;
            }
     }
    printf("Maximum value in the array is %dth term which is %d\n",j,max);


    
}

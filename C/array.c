#include <stdio.h>

void main(){
    // Find Maximum element in an array
    int arr[10];
    int size,max=0,i;
    printf("Enter the size of the array=");
    scanf("%d",&size);
    printf("Enter %d elements in the array\n=",size);
    for(i=1;i<=size;i++)
    {
        scanf("%d",&arr[i]);
    }
     for(i=1;i<=size;i++)
      {
        if(max>arr[i])
            max=arr[i];
     }
    printf("Maximum value in the array is %d=",max);


    
}

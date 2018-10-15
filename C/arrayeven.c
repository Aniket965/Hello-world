#include <stdio.h>

int main(){

    // Print even and odd numbers stored in the array
    int arr1[10];
    int i=0,evensum=0,size;

    printf("Enter the size of the array ");
    scanf("%d",&size);

    printf("\nEnter %d elements in the array\n",size);
    for(i=1;i<=size;i++){
        scanf("%d",&arr1[i]);
        if(arr1[i]%2==0)
        {
            evensum = evensum + arr1[i];
        }
       
    }
    printf("Sum of even elements of the array is %d\n",evensum);

    printf("\n");
    return 0;
}

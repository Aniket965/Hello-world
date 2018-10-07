#include <stdio.h>

int main(){

    // Print even and odd numbers stored in the array
    int arr1[10];
    int i=0,evensum=0,oddsum=0,size=0;

    printf("Enter the size of the array ");
    scanf("%d",&size);

    printf("\nEnter %d elements in the array\n",size);
    for(i=0;i<size;i++){
        scanf("%d",&arr1[i]);
        if(arr1[i]%2==0)
        {
            // Even Element
            evensum = evensum + arr1[i];
        }
        else{
            // Odd Element
            oddsum = oddsum + arr1[i];
        }
    }
    printf("Sum of even elements of the array is %d\nSum of Odd elements of the array is %d",evensum,oddsum);

    printf("\n");
    return 0;
}
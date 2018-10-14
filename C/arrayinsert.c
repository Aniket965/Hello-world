#include <stdio.h>

int main()
{
    int i,sizeofarray,arr[100];
    printf("Enter size of the array\n");
    scanf("%d",&sizeofarray);
    printf("Enter %d elements in the array\n",sizeofarray);

    for(i=0;i<sizeofarray;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nArray looks like\n");
    for(i=0;i<sizeofarray;i++)
    {
        printf("%d ",arr[i]);
    }

    printf("\n");
    return 0;
}
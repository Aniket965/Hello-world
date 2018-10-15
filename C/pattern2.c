#include <stdio.h>

int main()
{
    /*
    $$$*
    $$***
    $*****
    */
   int i,j,k;
    for(i=1;i<=8;i=i+2)  //i=1 i<=n, i++
    {
        for(j=6;j>=i;j=j-2) //j=1, j<=n-1
        {
            printf(" ");
        }
        for(k=1;k<=i;k++)  // k<=2*i-1
        {
            printf("*");
        }
        printf("\n");
    }




    printf("\n");
    return 0;
}
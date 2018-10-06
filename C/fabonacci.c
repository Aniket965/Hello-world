#include <stdio.h>

int main()
{
    int n,hold,a=0,b=1,i;
    // 0 1 2 3 5 8 13 21 n
    printf("Enter the n value ");
    scanf("%d",&n);

    i=2;
    hold =0;
    printf("0 ");
    while(i<=n)
    {
        hold = a+b;
        printf("%d ",hold);
        a=b;
        b=hold;
        i++;
    }

    printf("\n");
    return 0;
}
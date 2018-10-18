#include <stdio.h>

int main()
{
    int n;
    int i;
    int a;
    int b;
    int hold;
    a=0;
    b=1;
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

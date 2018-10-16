#include <stdio.h>
int main()
{
    int n1, n2, i, gcd;
    printf("Enter two integers: ");
    scanf("%d %d", &n1, &n2);
    for(i=1; i <= n1 && i <= n2; ++i)
    {
        if(n1%i==0&&n2%i==0)
        {
            gcd = i;
        }
    }
    printf("G.C.D = %d",gcd);
    return 0;
}

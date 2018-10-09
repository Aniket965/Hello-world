#include <stdio.h>

int main()
{
    int n1, n2;
    printf("Enter two numbers: ");
    scanf("%d%d",&n1,&n2);
    int num1=n1,num2=n2;
    while(n1 != n2)
    {
        if(n1 > n2)
            n1 -= n2;
        else
            n2 -= n1;
    }
    printf("gcd of %d and %d = %d",num1,num2,n1);
    return 0;
}

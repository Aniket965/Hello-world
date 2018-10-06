#include <stdio.h>

int main()
{
    // Factorial of a number 5= 5*4*3*2*1
    int fact=1;
    int i=0;
    int n;
    printf("Enter the number for which you want to calculate factorial ");
    scanf("%d",&n);

    i=n;

    while(i>0)
    {
        fact = fact*i;
        i--;
    }
    printf("Factorial of %d is %d",n,fact);

    printf("\n");
    return 0;
}

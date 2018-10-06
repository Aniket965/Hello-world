#include <stdio.h>

int main()
{
    // Factorial of a number 5= 5*4*3*2*1
    int fact=1,i=0,n;
    printf("Enter the number to calculate factorial ");
    scanf("%d",&n);

    i=n;

    while(i>0)
    {
        fact = fact*i;
        i--;
    }
    printf("Factorial is %d",fact);

    printf("\n");
    return 0;
}
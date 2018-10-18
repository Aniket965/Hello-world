#include <stdio.h>

int main()
{
    // We have to calculate the sum and product of the digits
    int sum=0,pro=1,i=0,rem,num;

    printf("Enter a number to calculate its sum and product of digits ");
    scanf("%d",&num);

    while(num>0)
    {
        rem = num%10;
        sum = sum + rem;
        pro = pro * rem;
        num = num / 10;
    }

    printf("Sum of all the digits is %d\nProduct of all the digits is %d",sum,pro);

    printf("\n");
    return 0;
}
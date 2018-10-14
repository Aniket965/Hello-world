#include <stdio.h>

int main(){
    // Prime numbers who are divisible by themselfs only or 1

    int num,i=2,flag=0;
    printf("Enter a value to check:\n");
    scanf("%d",&num);

    while(i<num)
    {
        if(num%i==0)
        {
            flag=1;
        }
    i++;
    }
    if(flag==0)
    {
        printf("Number %d is a prime number",num);
    }
    else
    {
        printf("Number %d is not a prime number",num);
    }

    printf("\n");
    return 0;
}

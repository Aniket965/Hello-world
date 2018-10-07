#include <stdio.h>

int main(){

    int num=0;
    printf("Enter a Number to check ");
    scanf("%d",&num);

    if(num>0)
    {
        printf("Number is positive");
    }
    if(num==0)
    {
        printf("Number is non Negative nor positive");
    }
    if(num<0)
    {
        printf("Number is a negative Number");
    }

    printf("\n");
    return 0;
}
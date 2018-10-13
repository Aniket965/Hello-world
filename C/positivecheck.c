#include <stdio.h>

int main(){

    int num;
    printf("Enter a Number to check \n");
    scanf("%d",&num);

    if(num>0)
    {
        printf("Number is a positive number.");
    }
    if(num==0)
    {
        printf("Number is neither negative nor positive.");
    }
    else
    {
        printf("Number is a negative number.");
    }

  
    return 0;
}

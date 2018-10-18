#include <stdio.h>

int main(){

    // Reverse of a value
    int value,reverse=0,remainder;
    printf("Enter a value ");
    scanf("%d",&value);

    while(value!=0)
    {
        remainder = value%10;
        reverse = remainder + (reverse*10);
        value = value/10;
    }
    printf("Reversed value is %d",reverse);

    printf("\n");
    return 0;
}

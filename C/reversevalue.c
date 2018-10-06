#include <stdio.h>

int main(){

    // Reverse of a value
    int value,reverse;
    printf("Enter a value ");
    scanf("%d",&value);

    while(value>0)
    {
        reverse = reverse*10;
        reverse = reverse + value%10;
        value = value/10;
    }
    printf("Reversed value is %d",reverse);

    printf("\n");
    return 0;
}
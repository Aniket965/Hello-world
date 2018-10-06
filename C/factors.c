#include <stdio.h>

int main(){

    // Factors of a value
    int num,i=2;

    printf("Enter a value to calculate ");
    scanf("%d",&num);

    while(i<num)
    {
        if(num%i==0)
        {
            printf("%d ",i);
        }
        i++;
    }

    printf("\n");
    return 0;
}
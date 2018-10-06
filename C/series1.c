#include <stdio.h>

int main(){

    // 1/1 + 1/2 + 1/3 + n
    // Sum also
    float sum=0,i,n;
    printf("Enter the end value ");
    scanf("%f",&n);
    i=1;
    while(i<=n)
    {
        printf("1/%f +",i);
        sum = sum + 1/i;
        i++;
    }
    printf("\n Sum is %f",sum);

    printf("\n");
    return 0;
}
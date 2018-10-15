
#include <stdio.h>
// By Dhiraj Saharia

int main()
{
    int a,b;
    printf("--Swapping without a Third Variable--\n");
    printf("Enter a and b:\n");
    scanf("%d %d",&a,&b);

    a = a+b;
    b = a - b;
    a = a - b;

    printf("After Swapping: a = %d and b = %d \n", a,b);

    return 0;
}

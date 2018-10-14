#include <stdio.h>
int main(){

    int num,i=0;
    printf("Enter a number to print its table ");
    scanf("%d",&num);

    while(i<=10)
    {
        printf("%dX%d=%d\n",num,i,num*i);
        i++;
    }

    printf("\n");
    return 0;
}
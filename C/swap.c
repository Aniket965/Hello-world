#include<stdio.h>
int main()
{
    int a,b,c;

    scanf("%d" , &a);
    scanf("%d" , &b);
    printf("First Number:%d",a);
    printf("Second Number:%d",b);
    
    c=a;
    a=b;
    b=c;
    printf("First Number:%d",a);
    printf("Second Number:%d",b);


}
#include<stdio.h>
int main()
{
    int a,m,c;

    scanf("%d" , &a);
    scanf("%d" , &m);
    printf("First Number:%d",a);
    printf("Second Number:%d",m);
    
    c=a;
    a=m;
    m=c;
    printf("First Number:%d",a);
    printf("Second Number:%d",m);

return 0;
}

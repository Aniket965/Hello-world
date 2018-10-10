#include<stdio.h>
int main()
{
    int a,m,c;
    
    printf(" Enter First Number : ");
    scanf("%d" , &a);
    printf(" Enter Second Number : ");
    scanf("%d" , &m);
    
    c=a;
    a=m;
    m=c;
    
    printf(" After swapping ...\n\n");
    printf(" First Number:%d",a);
    printf("\n Second Number:%d",m);

return 0;
}

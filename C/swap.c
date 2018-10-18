
#include<stdio.h>
int main()
{
    int a,m,c;
    
    printf(" Enter First Number : ");
    scanf("%d" , &a);
    printf(" Enter Second Number : ");
    scanf("%d" , &m);
    
    a=a+m;
    m=a-m;
    a=a-m;
    
    printf(" After swapping ...\n\n");
    printf(" First Number:%d",a);
    printf("\n Second Number:%d\n",m);

return 0;
}

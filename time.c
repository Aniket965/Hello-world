#include<stdio.h>
int main()
{
   int a,b,c;
    char d,e;
       scanf("%d:%d:%d%c%c",&a,&b,&c,&d,&e);
    if(a==12&&d=='A')
        a=00;
    if(a!=12&&d=='P')
    {
        a=a+12;
    }
    printf("%02d:%02d:%02d",a,b,c);
    return 0;
}

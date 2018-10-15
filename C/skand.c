#include<stdio.h>
int fac(int x);
int main()
{
     int n,m;
     printf("enter a number");
     scanf("%d",&n);
     m=fac(n);
     printf("%d",m);
     return 0;
}
int fac(int x)
{
     int z;
     if(x==0||x==1)
     return 1;
     else
     z=x*fac(x-1);
     return z;
}

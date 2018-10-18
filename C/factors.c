#include <stdio.h>
int a[100000];
int main(){

 int n,i;
    scanf("%d",&n);
    //smallest prime factor of any number i
    for(i=2;i<=n;i++)
    { if(a[i]==0)
            for(j=i;j<=n;j+=i)
           a[j]=i;
    }
    //prime factors of number n.
    while(n!=0)
    {
        printf("%d ",a[n]);
     n=n/a[n];
    }
    return 0;}

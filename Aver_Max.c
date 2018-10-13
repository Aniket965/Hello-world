#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n;
    scanf("%d",&n);
    while(n--)
    {
        long int c,b;
        scanf("%ld%ld",&c,&b);
        long double a[c],p;
        int i,j,k,l;
        for(i=0;i<c;i++)
        {
            scanf("%Lf",&a[i]);
        }
        p=0;
        for(i=0;i<c;i++)
        {
            if(a[i]>=p)
            {
                p=a[i];
            }
            if(-1.0*(a[i])>=p&&b>0)
            {
                p=-1.0*(a[i]);
            }
        }
        printf("%.1Lf\n",p);
    }
    return 0;
}

#include<stdio.h>
int main()
{
        long long num,count=0;int i;
        scanf("%lld",&num);
        for(i=2;i*i<=num;i++)
        {
            if(num%i==0)
            {
                int factor2=num/i;
                int k=i;
                while(k)
                {
                    int t=k%10;k/=10;
                    if(t==3||t==5||t==6){count++;break;}
                }
                if(k!=factor2)
                {
                    while(factor2)
                    {
                        int t=factor2%10;factor2/=10;
                        if(t==3||t==5||t==6){count++;break;}
                    }
                }
            }
        }
        while(num)
        {
            int t=num%10;
            num/=10;
            if(t==3||t==5||t==6){count++;break;}
        }
        printf("%lld\n",count);
    
}

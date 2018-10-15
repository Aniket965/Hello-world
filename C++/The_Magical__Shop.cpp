#include<iostream>
#include<string.h>
typedef long long int lli;
int main(){
    lli a,b,ans=0;
    char str[1000000];
    scanf("%lld%lld",&a,&b);
    scanf("%s",str);
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]=='1')
        {
            ans = (ans+a)%b;
        }
        a = ((a%b)*(a%b))%b;
    }
    printf("%lld",ans);
    return 0;
}

    #include<iostream>
    #include<algorithm> 
    using namespace std;
    long long int ans=1;
    long long int powermod(long long int a,long long int b,long long int m){
        if(b==0)
            return 1;
        if(b==1)
            return a;
        ans=powermod(a,b/2,m);
        ans=(ans*ans)%m;
        if(b%2==1)
            ans = (ans*a)%m;
        return ans;
    }
    int main(){
        long long int n,a[51],f,g;
        scanf("%lld%lld",&n,&a[0]);
        g=a[0];
        f=a[0];
        for(int i=1;i<n;i++){
            scanf("%lld",&a[i]);
            f=(f*a[i])%1000000007;
            g=__gcd(g,a[i]);
        }
        printf("%lld",powermod(f,g,1000000007));
    }

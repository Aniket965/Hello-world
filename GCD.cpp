#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define f(i,x,n) for(ll i=x;i<n;i++)
#define fl(i,x,n) for(ll i=n;i>=x;i--)
#define MOD (ll)1e9+7
#define print(x) cout<<x<<endl
#define vec vector<ll>
#define pai pair<ll, ll>
#define itr(it) :: iterator it
#define MAX (ll)1e16
#define MIN (ll)-1e16
using namespace std;
       ///////////   ///     ///   ///      ///   ////////////  ///      ///
       ///           ///     ///   ///      ///   ///      ///  ///      ///
       ///           ///     ///   ///      ///   ///      ///  ///      ///
       ///////////   ///////////   ///      ///   ////////////  ////////////
               ///   ///     ///   ///      ///   ///      ///  ///      ///
               ///   ///     ///   ///      ///   ///      ///  ///      ///
       ///////////   ///     ///   ////////////   ////////////  ///      ///
ll minn( ll a , ll b)
{
    if(a>b)
        return b;
    return a;
}
ll maxx( ll a , ll b)
{
    if(a>b)
        return a;
    return b;
}
ll gcdd(ll a, ll b)
{
    if(b==0)
        return a;
    else
        return gcdd(b,a%b);
}
ll dsum(ll n)
{
    ll sum=0;
    while(n>0)
    {
        sum+=n%10;
        n/=10;
    }
    return sum;
}
signed main()
{
    ll a,b;
    cin>>a>>b;
    cout<<gcdd(a,b)<<endl;
    return 0;
}

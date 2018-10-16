#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 100000

ll pow_(ll a, ll b, ll m)
{
    ll ans = 1;
    a = a % m;
    while (b) {
        if (b&1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

ll fact(ll x, ll m)
{
    ll ans = 1;
    while (x > 1) {
        ans = (ans * x) % m;
        x -= 1;
    }
    return ans;
}

ll ncr(ll n, ll r, ll m)
{
    if (r > n) return 0;
    
    ll a = fact(n, m);
    ll b = fact(r, m);
    ll c = fact(n-r, m);
    
    return (a * pow_(b*c, m-2, m)) % m;
}

int main()
{
    ll n, r, m;
    cin >> n >> r >> m;
    cout << ncr(n, r, m) << endl;
    
    return 0;
}

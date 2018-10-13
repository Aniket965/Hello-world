#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> fun(string str)
{
    ll n = str.length();
    vector<ll> f(n);
    f[0] = 0;

    for(ll i=1;i<n;i++)
    {
        ll j = f[i-1];
        while(j>0 && str[i]!=str[j])
        {
            j = f[j-1];
        }
        if(str[i]==str[j])
            j++;

        f[i] = j;

    }

    return f;
}

ll match(string txt,string str,vector<ll> v)
{
    ll ans = 0;

    ll ptr1 = 0;
    ll ptr2 = 0;

    while(ptr1<txt.length())
    {
        if(txt[ptr1]==str[ptr2])
        {
            ptr1++;
            ptr2++;
            if(ptr2 == str.length())
            {
                ptr2 = v[ptr2-1];
                ans++;
            }
        }

        else{
                if(ptr2 == 0)
                    ptr1++;
        else
            ptr2 = v[ptr2-1];
        }

    }

    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false);

    string text;  // abbabababadababab
    string pattern;  // aba

    cin>>pattern>>text;

    vector<ll> pref = fun(pattern);

    ll cnt = match(text,pattern,pref);  // 5

    return 0;
}

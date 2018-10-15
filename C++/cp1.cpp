#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    ll a, b, index;
}tree[4000005];
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    ll n, i, q;
    cin >> n;
    node a[n];
    for(i = 0; i < n; i++)
    {
        cin >> a[i].a;
        a[i].index = i + 1;
    }
    for(i = 0; i < n; i++)
        cin >> a[i].b;
    for(i = 0; i < n; i++)
        tree[i + n] = a[i];
    for(i = n - 1; i > 0; i--)
    {
        node left = tree[(i << 1)];
        node right = tree[(i << 1) | 1];
        if(left.a > right.a)
            tree[i] = left;
        else if(left.a == right.a)
        {
            if(left.b <= right.b)
                tree[i] = left;
            else
                tree[i] = right;
        }
        else
            tree[i] = right;
    }
    cin >> q;
    ll l, r;
    while(q--)
    {
        cin >> l >> r;
        node ans;
        ans.a = INT_MIN;
        ans.b = ans.index = INT_MAX;
        l--;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if(l & 1)
            {
                node left = tree[l++];
                if(left.a > ans.a || (left.a == ans.a && left.b <= ans.b))
                    ans = left;
            }
            if(r & 1)
            {
                node right = tree[--r];
                if(right.a > ans.a || (right.a == ans.a && right.b <= ans.b))
                    ans = right;
            }
        }
        cout << ans.index << endl;
    }
    return 0;
}

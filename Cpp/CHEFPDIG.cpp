// Problem : https://www.codechef.com/viewsolution/15275148

#include<bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define rep(i,n) for(int i=0;i<(n);++i)
#define sd(n) scanf("%d",&n)
#define sdll(n) scanf("%lld",&n)
#define prn(n) printf("%d\n",n)
#define prnll(n) printf("%lld\n",n)
#define pb(n) push_back(n)
#define MOD 1000000007z
#define MAX 32000
const int INF = 1<<29;
typedef unsigned long long ll;
////////////////////////////////////////////////////////////////////////////////
int main()
{
    int t;
    sd(t);
    while(t--){
        string s;
        cin >> s;
        int cnt[10];

        rep(i,10)
            cnt[i] = 0;
        int n = s.size();

        for(int i=0;i<n;i++){
            cnt[s[i]-48]++;
            if(cnt[s[i]-48] > 2)
                cnt[s[i]-48] = 2;
        }

        for(int i=65;i<=90;i++){
            int x = i/10 , y = i%10;

            if(x==y and cnt[x]!=2){
                continue;
            }

            if(cnt[x] and cnt[y]){
                cout << (char)i ;
            }
        }
        cout << endl;
    }
    return 0;
}

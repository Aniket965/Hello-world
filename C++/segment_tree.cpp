#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define umap unordered_map
#define pq priority_queue
#define sz(a) int((a).size()) 
#define rep(i,k,n) for (int i = k; i < n; ++i)
#define repr(i,k,n) for (int i = k; i >= n; --i)
#define all(c) (c).begin(),(c).end() 
#define test() long t;cin>>t;while(t--)
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0)
#define mod 1000000007
#define INF 0x3f3f3f3f
#define endl '\n'
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;


const int N=1e6+5;
int tree[2*N];
int a[N];

void build(int node,int st,int end){
    if(st==end)
        tree[node]=a[st];
    else{
        int mid=(st+end)/2;
        build(2*node,st,mid);
        build(2*node+1,mid+1,end);
        tree[node]=min(tree[2*node],tree[2*node+1]);
    }
}
void update(int node,int st,int end,int in,int val){
    if(st==end){
        a[in]=val;
        tree[node]=val;
    }
    else{
        int mid=(st+end)/2;
        if(st<=in && in<=mid)
            update(2*node,st,mid,in,val);
        else
            update(2*node+1,mid+1,end,in,val);
        tree[node]=min(tree[2*node],tree[2*node+1]);
    }
}
int query(int node,int st,int end,int l,int r){
    if(r<st || l>end)
        return INF;
    if(l<=st && r>=end)
        return tree[node];
    int mid=(st+end)/2;
    int q1=query(2*node,st,mid,l,r);
    int q2=query(2*node+1,mid+1,end,l,r);
    return min(q1,q2);
}

int main() {
    fastIO;
    string s;
    int n,q;
    cin>>n>>s;
    // rep(i,1,n+1)
    //     cin>>a[i];
    build(1,1,n);
    char c; int x,y;
    rep(i,0,q){
        cin>>c>>x>>y;
        if(c=='q')
            cout<<query(1,1,n,x,y)<<endl;
        else
            update(1,1,n,x,y);
    }
    return 0;
}


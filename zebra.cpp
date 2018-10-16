#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define MAX 200005
#define MOD 1000000007
#define max(a,b) (a>=b?a:b)
#define min(a,b) (a<b?a:b)
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define si set<int>
#define mp map<ll,ll>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main()
{ 


	string s;
	cin >> s;
	s+=s;
	int ans=0,l=0;
	for (int i=0;i<s.size();i++)
	{
		if (i && s[i]==s[i-1])
		l=i;
		ans=max(ans,i-l+1);
	}
	printf("%d",min(ans,(int)s.size()/2));

}
	
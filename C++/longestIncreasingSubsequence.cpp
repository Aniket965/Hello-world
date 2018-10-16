#include <vector>
#include <queue>
#include <string>
 
#define ll long long
 
using namespace std;

int a[1000];

int main()
{
	int t,i,j;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		memset(a,0,sizeof a);
		vector<int> lis;
		lis.clear();
		for(i=0;i<n;i++)
			cin>>a[i];
		for(i=0;i<n;i++)
		{
			auto ind=lower_bound(lis.begin(),lis.end(),a[i]);
			if(ind==lis.end())
				lis.push_back(a[i]);
			else
				lis[ind-lis.begin()]=a[i];
		}
		cout<<lis.size()<<endl;
	}
	return 0;
}
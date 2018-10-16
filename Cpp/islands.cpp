//https://www.geeksforgeeks.org/find-number-of-islands/
#include<bits/stdc++.h>
using namespace std;
vector<int> print(int** edges,int n,int sv,bool* visited,vector<int> ans)
{
	ans.push_back(sv);
	visited[sv]=true;
	for(int i=1;i<=n;i++)
	{
		if(i==sv)
			continue;
		
		if(edges[sv][i]==1)
		{
		   if(visited[i])
				continue;
		   print(edges,n,i,visited,ans);	
		}
	}
	return ans;
}
int main()
{
	int n,e;
	cin>>n>>e;
	int** edges=new int*[n+1];
	
	for(int i=1;i<=n;i++)
	{
		edges[i]=new int[n];
		for(int j=1;j<=n;j++)
		edges[i][j]=0;
	}
	
	int u[100],v[100];
	
	for(int i=0;i<e;i++)
		cin>>u[i];

	
	for(int i=0;i<e;i++)
	cin>>v[i];
	
	for(int i=0;i<e;i++)
	{
			edges[u[i]][v[i]]=1;
			edges[v[i]][u[i]]=1;	
	}
	
	int c=0;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		cout<<edges[i][j]<<" ";
		cout<<endl;
	}
	
	cout<<endl;
	bool* visited=new bool[n+1];
	
	for(int i=1;i<=n;i++)
	{
		visited[i]=false;
	}
	
	vector<int> vec;
	
	for(int i=1;i<=n;i++)
	{
		if(!visited[i])
		{
			c++;
			vector<int> ans=print(edges,n,i,visited,vec);    
    	}
	}
	
	cout<<c;
}




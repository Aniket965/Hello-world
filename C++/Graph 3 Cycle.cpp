#include<bits/stdc++.h>
using namespace std;
 
int countCycles(int **edges,int c,int n)
{
	int count=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(edges[i][j]==1 && j!=i)
			{
				
			
			for(int k=1;k<=n;k++)
			{
				if(edges[j][k]==1 && (k!=j )&& (k!=i))
				{
					if(edges[k][i]==1 && k!=i && k!=j)
					count++;
				}
			}
		}
		}
	}
	return count/6;//because 3! ways of arranging same i,j,k.we are detecting one cycle 6 times.
} 
int main()
{
	int n,m;
	cin>>n>>m;
	int **edges=new int*[n];
	for(int i=1;i<=n;i++)
	{
		edges[i]=new int[n];
		for(int j=1;j<=n;j++)
		edges[i][j]=0;
	}
	int u[m],v[m];
	for(int i=0;i<m;i++)
	{
		cin>>u[i];
		
		
	}
	
	for(int i=0;i<m;i++)
	cin>>v[i];
		for(int i=0;i<m;i++)
	{
		
			edges[u[i]][v[i]]=1;
			edges[v[i]][u[i]]=1;
		
	}

    int cyc = 3;
    cout << "Total cycles of length " << cyc << " are "
         << countCycles(edges, cyc,n);
    return 0;
}

#include<bits\stdc++.h>
using namespace std;
int min_1(int a[],bool b[],int v)
{
	int p=INT_MAX;int min_index=0;
	for(int i=0;i<v;i++)
	{
		if(a[i]<p && b[i]==false)
		{
			p=a[i];min_index=i;
		}
	}
	return min_index;
}
void print_distance(int d[],int s,int v)
{
	for(int i=0;i<v;i++)
	{
		cout<<s<<" "<<i<<" "<<d[i]<<endl;
	}
}
void dijkshas(int g[9][9],int v,int s)
{
	int d[v];bool m[v];
	for(int i=0;i<v;i++)
	{
		d[i]=INT_MAX;m[i]=false;
	}
	d[s]=0;
	for(int i=0;i<v-1;i++)
	{
		int u=min_1(d,m,v);
		m[u]=true;
	for(int j=0;j<v;j++)
	{
		if(g[u][j] && m[j]==false && d[u]+g[u][j]<d[j])
		{
			d[j]=d[u]+g[u][j];
		}
	}
	}
	print_distance(d,s,v);
}
int main()
{
	int g[9][9] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
 	dijkshas(g,9,1);
}

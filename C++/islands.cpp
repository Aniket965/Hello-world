#include<bits/stdc++.h>

using namespace std;

int graph[10][10];
bool visited[10][10]; 
int n;

int dfs(int x,int y){
	
	if(x<1 || x>n || y<1 || y>n )
		return 0;

	
	if(visited[x][y] || !graph[x][y])
		return 0;
	
	visited[x][y] = true;
	

	if(!visited[x-1][y-1] && graph[x-1][y-1]==1)
		dfs(x-1,y-1);
	

	if(!visited[x-1][y] && graph[x-1][y]==1)
		dfs(x-1,y);
	

	if(!visited[x][y-1] && graph[x][y-1]==1)
		dfs(x,y-1);
	

	if(!visited[x+1][y+1] && graph[x+1][y+1]==1)
		dfs(x+1,y+1);
	


	if(!visited[x+1][y] && graph[x+1][y]==1)
		dfs(x+1,y);
	

	if(!visited[x-1][y+1] && graph[x-1][y+1]==1)
		dfs(x-1,y+1);
	

	if(!visited[x+1][y-1] && graph[x+1][y-1]==1)
		dfs(x+1,y-1);
	

	if(!visited[x][y+1] && graph[x][y+1]==1)
		dfs(x,y+1);
	
}

int main(){
	
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>graph[i][j];
	int count=0;

	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(!visited[i][j]&&graph[i][j]){
				dfs(i,j);
				count++;
			}
	cout<<count<<endl;

}

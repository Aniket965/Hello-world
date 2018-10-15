#include <bits/stdc++.h>
//max amount of vertices of the problem
#define MAXN 100000

using namespace std;

vector<int> g[MAXN];
int vis[MAXN];

void dfs(int u){
	vis[u] = 1; // visiting
	for(int i = 0;i < g[u].size(); i++){
		int v = g[u][i];
		if(!vis[v]){ // if not visited
			dfs(v);
		}
	}
}


int main(){
	//filling vis with zeros
	memset(vis, 0, sizeof vis);
	
	// N = number of vertices
	// M = numbers of conections of each 
	int N, M;

	/*
		U have to read the connections of the vertice g[i]
		g[i].push_back(vertice that it's connected to - a unique number)
	*/

	// u can run dfs() in the way that suits your problem
}


/* 
EXAMPLE OF USE OF A DFS -> PROBLEM 2562 of URI Online Judge

#include <bits/stdc++.h>
#define MAXN 100000
#define ii pair<int,int>

using namespace std;

vector<int> g[MAXN];
int vis[MAXN];

int resp;

bool dfs(int u){
	vis[u] = 1;
	for(int i=0;i<g[u].size();i++){
		int v = g[u][i];
		if(vis[v] == 1){
			return 1;
		}else if(vis[v] == 0){
			resp++;
			int ret = dfs(v);
			if(ret == 1)
				return 1;
		}
	}
	vis[u] = 2;
	return 0;
}


int main(){
	int n, m;
	while( scanf("%d %d", &n, &m) != EOF ){ 
		//limpando o vetor de visitados
		memset(vis, 0, sizeof vis);
		resp = 1;

		// atribuindo as relações do grafo
		for(int i=0;i<m;i++){
			ii p;
			scanf("%d %d", &p.first, &p.second);
			p.first--;
			p.second--;
			g[p.first].push_back(p.second);
		}
		int comeco;
		scanf("%d", &comeco);
		comeco--;
		dfs(comeco);

		printf("%d\n", resp);

		//limpando o grafo
		for(int i=0;i<n;i++){
			g[i].clear();
		}
	}
	return 0;
}
*/
#include <bits/stdc++.h>

using namespace std;

/**
    adj[node1].push_back(make_pair(node2,weight))

    and dist is set to infinite initially while src is the source
    dijstra's algorithm
*/

void shortest(int n,vector < pair<int,int> > adj[],vector<int> &dist,int src){
	set < pair <int,int> > sp;
	sp.insert(make_pair(0,src));
	dist[src] = 0;
	while(!sp.empty()){
		pair <int,int> temp = *(sp.begin());
		sp.erase(sp.begin());
		int u = temp.second;
		for(int i=0;i<adj[u].size();i++){
			int v = adj[u][i].first;
			int w = adj[u][i].second;
			if(dist[v] > dist[u]+w){
				if(dist[v] != INT_MAX){
					sp.erase(sp.find(make_pair(dist[v],v)));
				}
				dist[v] = dist[u]+w;
				sp.insert(make_pair(dist[v],v));
			}
		}
	}
}

int main(){
    return 0;
}


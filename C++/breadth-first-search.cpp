vector<bool> visited;
vector<int> graph[1001];
vector<int> val;

void edge(int u,int v){
	graph[u].pb(v);
	graph[v].pb(u);
}

void bfs(int s){
	int weight=0;
	queue<int> q;
	q.push(s);
	visited[s]=true;
	while(!q.empty()){
		int f=q.front();
		q.pop();
		weight+=6;
		//cout<<f<<" ";
		for(auto i=graph[f].begin();i!=graph[f].end();++i){
			if(!visited[*i]){
				q.push(*i);
				visited[*i]=true;
				val[*i]=weight;
			}
		}
	}
}

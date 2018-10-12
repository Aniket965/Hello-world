void dfs(int s) {
        visited[s] = true;
        for(int i = 0;i < adj[s].size();++i)    {
         if(visited[adj[s][i]] == false)
             dfs(adj[s][i]);
        }
    }

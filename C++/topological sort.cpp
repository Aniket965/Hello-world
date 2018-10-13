#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class Graph
{
private:
    int V;
    list<int> *adj;
    void Dfsutil(int i,vector<bool> &visited,stack<int> &st);
public:
    Graph(int v);
    void addEdge(int u,int v);
    void DFS();
};

Graph::Graph(int v)
{
    V = v;
    adj = new list<int>[V];

}

void Graph::addEdge(int u,int v)
{
    adj[u].push_back(v);
}


void Graph::Dfsutil(int i,vector<bool> &visited,stack<int> &st)
{
    visited[i] = true;

    for(list<int>::iterator itr = adj[i].begin();itr!=adj[i].end();itr++)
    {
        if(!visited[*itr])
        {
            Dfsutil(*itr,visited,st);
        }
    }

    st.push(i);

}


void Graph::DFS()
{
    stack<int> st;

    vector<bool> visited(V,false);

    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            Dfsutil(i,visited,st);
        }
    }

    cout<<"topological sort is : ";

    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }

}

int main()
{

    int v,e;

    cout<<"enter number of vertices and edges of directed acyclic graph\n";
    cin>>v>>e;

    Graph gr(v);

    for(int i=0;i<e;i++)
    {
        int a,b;
        cout<<"enter vertices of an directed edge from u to v\n";
        cin>>a>>b;
        gr.addEdge(a,b);
    }

    gr.DFS();

    return 0;
}

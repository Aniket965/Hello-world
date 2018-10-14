#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int source;
    int destination;
    Edge(int a, int b){
        source = a;
        destination = b;
    }
};
struct Graph{
    vector <int> vertices;
    vector <Edge> edges;
};

// Complexity of searching might be O(n) in worst case
int findSet(int parent[],int i){
    if(parent[i] == -1){
        return i;
    }
    return findSet(parent , parent[i]);
}

void unionSets(int parent[], int a, int b){
    parent[a] = b;
}

int isCycle(Graph g){
    int parent[100];
    int i,j,k,a,b;
    for(i=0;i<g.vertices.size();++i){
        parent[i] = -1;
    }

    for(i=0;i<g.edges.size();++i){
        a = findSet(parent, g.edges[i].source);
        b = findSet(parent, g.edges[i].destination);
        if(a != b){
            unionSets(parent, a, b);
        }
        else if(a==-1 && b ==-1){
            unionSets(parent, g.edges[i].source, g.edges[i].destination);
        }
        else{
            return 1;
        }
    }
    return 0;
}

int main(){
    Graph g;
    int v[] = {0,1,2,3,4,5};
    g.vertices =  vector <int> (v, v + sizeof(v)/sizeof(v[0]));

    g.edges.push_back(Edge(0,2));
    g.edges.push_back(Edge(1,4));
    g.edges.push_back(Edge(5,4));
    g.edges.push_back(Edge(1,0));
    g.edges.push_back(Edge(3,5));

    if(isCycle(g)){
        cout<<"Cycle is there";
    }
    else
        cout<<"No Cycle";


}
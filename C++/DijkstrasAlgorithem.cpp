#include<iostream>
#include<list>
#include<queue>
using namespace std;
typedef pair<int,int> pii;

class comp{ /// comparission in priority queue
public:
    bool operator()(pii a, pii b){
        return a.second>b.second;
    }
};

class Graphs{
private:
    list<pii> *adjList;
    int V;
public:
    Graphs(int n){
        V=n;
        adjList=new list<pii>[V];
    }
    void addEdge(int s, int d, int wt){
        adjList[s].push_back(make_pair(d,wt)); 
    }
    int dijikstra(int s, int d){ ///algorigthm to find shortest distance
        priority_queue<pii,vector<pii>,comp> pq;
        int * distance=new int[V];
        for (int i=0;i<V;i++) distance[i]=100000; 
        distance[s]=0;
        pq.push(make_pair(s,0));
        while (!pq.empty()){
            pii f=pq.top();
            pq.pop();
            int curVer=f.first;
            int curDist=f.second;
            if (distance[curVer]!=curDist) continue;
                 it!=adjList[curVer].end();it++){
                int childDist=it->second+curDist;
                if (childDist<distance[it->first]){ ///check the distance shortest ahi tabhi update krna
                    pq.push(make_pair(it->first,childDist));
                    distance[it->first]=childDist;
                }
            }
        }
        for (int i=0;i<V;i++){
            cout<<"Distance of vertex - "<<i<<" is "<<distance[i]<<endl;
        }
        cout<<endl;
        return distance[d];
    }
};

int main(){
    Graphs g(7);
    g.addEdge(0,1,20);
    g.addEdge(0,2,10);
    g.addEdge(1,4,20);
    g.addEdge(1,3,10);
    g.addEdge(2,3,25);
    g.addEdge(2,5,27);
    g.addEdge(3,4,5);
    g.addEdge(3,5,10);
    g.addEdge(4,6,5);
    g.addEdge(5,6,7);
    cout<<"The shortest path is "<<endl<<g.dijikstra(0,6)<<endl;
}

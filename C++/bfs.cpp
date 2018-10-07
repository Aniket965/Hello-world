#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(){

	int x,y,v,edges;
	cout<<"The number of edges: ";
	cin>>edges;

	vector<bool> visited(10,false);  // considering number of edges in graph to be less than 10
	vector<int> graph[10];
	queue<int> queue;

	cout<<"There is a branch between: \n";
	for(int i=0;i<edges;i++){
		cin>>x>>y;
		graph[x].push_back(y);
		//graph[y].push_back(x);
	}

	cout<<"Enter the vertex where you want the bfs transversal to start: \n";
	cin>>v;

	queue.push(v);
	visited[v]=1;
	//cout<<v<<endl;

	while(!queue.empty()){

		v = queue.front();
		queue.pop();

		cout<<v;

		

		for(std::vector<int>::iterator i=graph[v].begin();i!=graph[v].end();i++){

			if(!visited[*i]){
				//cout<<*i<<endl;
				visited[*i]=true;
				queue.push(*i);
			}
		}
	}
}
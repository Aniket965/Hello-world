/* DFS implementation using Stack... Works well in graphs without cycles */
#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main(){

	int x,y,v,edges;
	cout<<"The number of edges: ";
	cin>>edges;

	vector<bool> visited(10,false);  // considering number of edges in graph to be less than 10
	vector<int> graph[10];
	stack<int> stack;

	cout<<"There is a branch between: \n";
	for(int i=0;i<edges;i++){
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	cout<<"Enter the vertex where you want the transversal to start: \n";
	cin>>v;

	stack.push(v);
	visited[v]=1;
	cout<<v<<endl;

	while(!stack.empty()){

		v = stack.top();
		stack.pop();

		

		for(std::vector<int>::iterator i=graph[v].begin();i!=graph[v].end();i++){

			if(!visited[*i]){
				cout<<*i<<endl;
				visited[*i]=true;
				stack.push(*i);
			}
		}
	}
}
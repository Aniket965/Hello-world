#include <iostream>

using namespace std;


int main() {
	
	int n, e;

	cout<<"Enter number of nodes and edges :"<<"\n";

	cin>>n>>e;

	// graph[][] is adjacency matrix which is used to represent graph
	int graph[n][n],color[n];

	for(int i=0; i<n;i++){

		color[i]=0;

		for(int j=0; j<n; j++){

			graph[i][j]=0;

		}

	}

	cout<<"Enter edges:"<<"\n";
	
	for(int i =0; i<e;i++){

		int n1,n2;

		cin>>n1>>n2;
 		// Set edges equal to 1 if edge between nodes n1 and n2 is present else 0 
		graph[n1-1][n2-1]=graph[n2-1][n1-1]=1;

	}
 	// keeps track of colors of particular vertex 
	color[0]=1; // assign color 1 to vertex 0 

	//In this we loops check from vertex 1 to n and assigns the lowest possible color to them
	for(int i=1; i<n;i++){

		int x =1;  // represent present color and initialize it in every iteration 

		for(int j=0; j<n; j++){
			// check if vertex i has an adjacent vertex j and if vertex j has color as x 
			if(graph[i][j] && color[j]==x)
				 x++; // if yes then change color to next availabe color 
 
		}
		// assign the lowest possible color to vertex i 
		color[i]=x;
 
	}

	
for(int i=0; i<n; i++){

		cout<<"Vertex "<<i<<" Color "<<color[i]<<"\n";
 
	}

	return 0;

}

// A C++ program to print Eulerian circuit in given 
// directed graph using Hierholzer algorithm 
#include <bits/stdc++.h> 
using namespace std; 

void printCircuit(vector< vector<int> > adj) 
{ 
	// adj represents the adjacency list of 
	// the directed graph 
	// edge_count represents the number of edges 
	// emerging from a vertex 
	unordered_map<int,int> edge_count; 

	for (int i=0; i<adj.size(); i++) 
	{ 
		//find the count of edges to keep track 
		//of unused edges 
		edge_count[i] = adj[i].size(); 
	} 

	if (!adj.size()) 
		return; //empty graph 

	// Maintain a stack to keep vertices 
	stack<int> curr_path; 

	// vector to store final circuit 
	vector<int> circuit; 

	// start from any vertex 
	curr_path.push(0); 
	int curr_v = 0; // Current vertex 

	while (!curr_path.empty()) 
	{ 
		// If there's remaining edge 
		if (edge_count[curr_v]) 
		{ 
			// Push the vertex 
			curr_path.push(curr_v); 

			// Find the next vertex using an edge 
			int next_v = adj[curr_v].back(); 

			// and remove that edge 
			edge_count[curr_v]--; 
			adj[curr_v].pop_back(); 

			// Move to next vertex 
			curr_v = next_v; 
		} 

		// back-track to find remaining circuit 
		else
		{ 
			circuit.push_back(curr_v); 

			// Back-tracking 
			curr_v = curr_path.top(); 
			curr_path.pop(); 
		} 
	} 

	// we've got the circuit, now print it in reverse 
	for (int i=circuit.size()-1; i>=0; i--) 
	{ 
		cout << circuit[i]; 
		if (i) 
		cout<<" -> "; 
	} 
} 

// Driver program to check the above function 
int main() 
{ 
	vector< vector<int> > adj1, adj2; 

	// Input Graph 1 
	adj1.resize(3); 

	// Build the edges 
	adj1[0].push_back(1); 
	adj1[1].push_back(2); 
	adj1[2].push_back(0); 
	printCircuit(adj1); 
	cout << endl; 

	// Input Graph 2 
	adj2.resize(7); 
	adj2[0].push_back(1); 
	adj2[0].push_back(6); 
	adj2[1].push_back(2); 
	adj2[2].push_back(0); 
	adj2[2].push_back(3); 
	adj2[3].push_back(4); 
	adj2[4].push_back(2); 
	adj2[4].push_back(5); 
	adj2[5].push_back(0); 
	adj2[6].push_back(4); 
	printCircuit(adj2); 

	return 0; 
} 

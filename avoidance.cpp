// A C++ Program for Resource Allocation Graph - Deadlock Avoidance
#include<iostream>
#include <list>
#include <limits.h>
#include<stdlib.h> 
#include<algorithm>
using namespace std;
 
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    bool isCyclicUtil(int v, bool visited[], bool *rs);  // used by isCyclic()
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // to add an edge to graph
    void removeEdge(int v, int w); // to remove an edge to graph
    bool existEdge(int v, int w);
    bool isCyclic();    // returns true if there is a cycle in this graph
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
void Graph::removeEdge(int v, int w)
{
	adj[v].remove(w); // Remove w from v's list
}

bool Graph::existEdge(int v, int w)
{ 
    return (std::find(adj[v].begin(), adj[v].end(), w) != adj[v].end());   
     
}
 
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
{
    if(visited[v] == false)
    {
        // Mark the current node as visited and part of recursion stack
        visited[v] = true;
        recStack[v] = true;
 
        // Recur for all the vertices adjacent to this vertex
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) )
                return true;
            else if (recStack[*i])
                return true;
        }
 
    }
    recStack[v] = false;  // remove the vertex from recursion stack
    return false;
}
 
// Returns true if the graph contains a cycle, else false.
bool Graph::isCyclic()
{
    // Mark all the vertices as not visited and not part of recursion
    // stack
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
 
    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for(int i = 0; i < V; i++)
        if (isCyclicUtil(i, visited, recStack))
            return true;
 
    return false;
}
 
int main()
{
    int r, choice, rno, pno;
    cout<<"\n Enter the total number of resources: ";
	cin>>r;
	int p, alloc[r];
	cout<<"\n Enter the total number of processes: ";
	cin>>p;
	//First r vertices are resource vertices and next p vertices are process vertices
	//Crearte graph with r+p vertices
    Graph g(r+p);
    
   	for(int i=0;i<p;i++)
     {  int c;
        cout<<"\n Number of resources process "<<i+1<<" "<<" wants to claim ";
        cin>>c;
        for(int j=0;j<c;j++) 
          {
		  int res_no;
		  cout<<"\n Enter resource number to claim ";
		  cin>>res_no;
		  g.addEdge(r+i, res_no-1); 
		  }
	 }
    
    for(int i = 0; i < r; i++)
    {
    	alloc[i] = 0;
	}
    while(1)
    {
    	cout<<"\n--------------------------------------------------";
		cout<<"\n Choose your preference: \n 1. Request \n 2. Release \n 3. Exit \n";
		cout<<"--------------------------------------------------\n";
    	cin>>choice;
	    switch(choice)
	    {
	    	case 1:
	        	  	cout<<"\n Enter process number: ";
	        	  	cin>>pno;
	        	  	
					if(pno>p)
	        	  	{ 
					  cout<<"\n Process doesn't exist. Please enter any existing process ";
					  cin>>pno;
					} 
				    
					cout<<"\n Enter resource number to be requested: ";
	        	  	cin>>rno;
	        	  	
	        	  	if(rno>r)
	        	  	{ 
					  cout<<"\n Resource doesn't exist. Please enter any valid resource number ";
					  cin>>pno;
					} 
				    
	        	  	//check if resource had already been allocated
	        	  	if(g.existEdge(rno-1,pno+r-1))
	        	  	{
					  cout<<"\n The resource is already being held by the process ";
					  break;
				    }
	        	  		        	  	
	        	  	
	        	  	//check if the process had claimed the resource
					if(!g.existEdge(pno+r-1,rno-1))
	        	  	{
					  cout<<"\n The resource wasn't claimed earlier by the process ";
				    }
	        	  	
					else
					{//remove claim edge, add request edges to the graph and check for cycle
		    			g.removeEdge(r+pno-1, rno-1);
		    			g.addEdge(rno-1, r+pno-1);
		    			//if cycle exists, revert back to previous stage
						if(g.isCyclic())
		        		{
							cout <<"\n Cycle Detected. Allocating the resource will lead to an unsafe state. \n";
							g.removeEdge(rno-1, r+pno-1);
		    				g.addEdge(r+pno-1, rno-1);
						}
		    			else
		        		{	//a previously allocated resource cannot be reallocated
		        			if(alloc[rno-1])
		        			{
								cout<<"\n Resource has been allocated already. \n";
								g.removeEdge(rno-1, r+pno-1);
		    					g.addEdge(r+pno-1, rno-1);       					
							}
							//resource is successfully allocated
							else
		        			{
							cout <<"\n Requested resource has been allocated. \n";
							alloc[rno-1] = 1;
							}
			 			}
			    	}
	        		break;
	        case 2:
	        	  	cout<<"\n Enter process number: ";
	        	  	cin>>pno;
	        	  	
					if(pno>p)
	        	  	{ 
					  cout<<"\n Process doesn't exist. Please enter any existing process ";
					  cin>>pno;
					} 
				    
					cout<<"\n Enter resource number to be requested: ";
	        	  	cin>>rno;
	        	  	
	        	  	if(rno>r)
	        	  	{ 
					  cout<<"\n Resource doesn't exist. Please enter any valid resource number ";
					  cin>>pno;
					} 
				
                  //check if process actually holds the resource
	        	  if(!g.existEdge(rno-1,pno+r-1))
				  {
				   cout<<"\n This process doesn't hold this resource ";
				  }
				  
				  //allocated edge converted to claim edge
				  else
	        	  {
				   g.removeEdge(rno-1, r+pno-1);
	    		   g.addEdge(r+pno-1, rno-1);
	    		   alloc[rno-1] = 0;
				   cout <<"\n Resource released from the process. \n";
	    		  }
	    		  
				  break;
	    	case 3:
	    		exit(0);
	        	
		}
	}	
    return 0;
}



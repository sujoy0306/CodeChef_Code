// A C++ Program to detect cycle in a graph
#include<iostream>
#include <list>
#include <limits.h>
#include<cstdio>
using namespace std;
long long int c=0;
class Graph
{
	long long int V; // No. of vertices
	list<long long int> *adj; // Pointer to an array containing adjacency lists
	bool isCyclicUtil(long long int v, bool visited[], bool *rs); // used by isCyclic()
public:
	Graph(long long int V); // Constructor
	void addEdge(long long int v,long long int w); // to add an edge to graph
	void isCyclic(); // returns true if there is a cycle in this graph
};

Graph::Graph(long long int V)
{
	this->V = V;
	adj = new list<long long int>[V];
}

void Graph::addEdge(long long int v,long long int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

// This function is a variation of DFSUytil() in http://www.geeksforgeeks.org/archives/18212
bool Graph::isCyclicUtil(long long int v, bool visited[], bool *recStack)
{
	if(visited[v] == false)
	{
		// Mark the current node as visited and part of recursion stack
		visited[v] = true;
		recStack[v] = true;

		// Recur for all the vertices adjacent to this vertex
		list<long long int>::iterator i;
		for(i = adj[v].begin(); i != adj[v].end(); ++i)
		{
			if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) ){
				return true;
			}
			else if (recStack[*i]){
				c++;
				recStack[*i]=false;
				return false;
			}
		}

	}
	recStack[v] = false; // remove the vertex from recursion stack
	return false;
}

// Returns true if the graph contains a cycle, else false.
// This function is a variation of DFS() in http://www.geeksforgeeks.org/archives/18212
void Graph::isCyclic()
{
	// Mark all the vertices as not visited and not part of recursion
	// stack
	bool *visited = new bool[V];
	bool *recStack = new bool[V];
	for(long long int i = 0; i < V; i++)
	{
		visited[i] = false;
		recStack[i] = false;
	}

	// Call the recursive helper function to detect cycle in different
	// DFS trees
	for(long long int i = 0; i < V; i++){
		bool k=isCyclicUtil(i, visited, recStack);
	}
}

int main()
{
	// Create a graph given in the above diagram
	long long int t;
    	scanf("%lld",&t);
    	while(t--){
		long long int n,i,val;
		scanf("%lld",&n);;
		Graph g(n);
		c=0;
		for(i=0;i<n;i++){
			scanf("%lld",&val);
			g.addEdge(i,((i+val+1)%n));
		}
 		g.isCyclic();
	 	printf("%lld\n",c);	
      	}
	return 0;
}


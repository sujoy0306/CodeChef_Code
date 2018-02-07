// A DFS based approach to find if there is a cycle
// in a directed graph. This approach strictly follows
// the algorithm given in CLRS book.
//#include <bits/stdc++.h>
#include<iostream>
#include<list>
using namespace std;
long long int count,val;
enum Color {WHITE, GRAY, BLACK};

// Graph class represents a directed graph using
// adjacency list representation
class Graph
{
	long long int V; // No. of vertices
	list<long long int>* adj; // adjacency lists

	// DFS traversal of the vertices reachable from v
	bool DFSUtil(long long int v,long long int color[]);
public:
	Graph(long long int V); // Constructor

	// function to add an edge to graph
	void addEdge(long long int v,long long int w);

	void isCyclic();
};

// Constructor
Graph::Graph(long long int V)
{
	this->V = V;
	adj = new list<long long int>[V];
}

// Utility function to add an edge
void Graph::addEdge(long long int v,long long int w)
{
	adj[v].push_back(w); // Add w to v's list.
}

// Recursive function to find if there is back edge
// in DFS subtree tree rooted with 'u'
bool Graph::DFSUtil(long long int u,long long int color[])
{
	// GRAY : This vertex is being processed (DFS
	//		 for this vertex has started, but not
	//		 ended (or this vertex is in function
	//		 call stack)
	color[u] = GRAY;

	// Iterate through all adjacent vertices
	list<long long int>::iterator i;
	for (i = adj[u].begin(); i != adj[u].end(); ++i)
	{
		long long int v = *i; // An adjacent of u

		// If there is
		if (color[v] == GRAY){
		count++;
		val=v;
		color[v]=BLACK;
		return true;
		}

		// If v is not processed and there is a back
		// edge in subtree rooted with v
		if (color[v] == WHITE && DFSUtil(v, color)){
		count++;
		if(val==v){
			count--;
			//color[u]=BLACK;
			return false;
		}
		return true;
		}
	}

	// Mark this vertex as processed
	color[u] = BLACK;

	return false;
}

// Returns true if there is a cycle in graph
void Graph::isCyclic()
{
	// Initialize color of all vertices as WHITE
	long long int *color = new long long int[V];
	for (long long int i = 0; i < V; i++)
		color[i] = WHITE;

	// Do a DFS traversal beginning with all
	// vertices
	 count=0;
	for (long long int i = 0; i < V; i++){
		if (color[i] == WHITE){
			bool v=DFSUtil(i, color);
		}
	}
	cout<<count<<endl;
	//return false;
}
int main(){
    long long int t;
    cin>>t;
    while(t--){
	long long int n,i,val;
	cin>>n;
	Graph g(n);
	for(i=0;i<n;i++){
		cin>>val;
		g.addEdge(i,((i+val+1)%n));
	}
 	g.isCyclic();	
    }
    return 0;
}

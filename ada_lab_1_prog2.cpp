/*A program to find connected components in an undirected graph using DFS

Using DFS/BFS, given an undirected graph, print all connected components line by line.
*/
#include <iostream>
using namespace std;

void DFS(int v, int **adj, bool *visited, int n){
	cout<<v;
	visited[v] = true;
	for(int i = 0; i<n ; i++){
		if(adj[v][i] == 1 && visited[i] == false)
			DFS(i,adj,visited,n);
	}
}

int main()
{
	int n, **adj;
	bool *visited;
	cout<<"Enter the number of nodes :";
	cin>>n;
	adj = new int *[n];
	for(int i = 0; i<n; i++)
		adj[i] = new int[n];
	visited  = new bool[n];
	cout<<"Enter the adjacency matrix :\n";
	for(int i =0; i<n; i++){
		cout<<"Adjacency for vertex "<<i<<":\n";
		for(int j =0; j<n; j++)
			cin>>adj[i][j];
	}
	
	for(int i =0; i<n; i++)
		visited[i]= false;
	cout<<"Connected vertices are : \n";
	for(int i =0; i<n; i++){
		if(visited[i] == false){
			DFS(i,adj,visited,n);
			cout<<"\n";
		}
	}
	return 0;
}

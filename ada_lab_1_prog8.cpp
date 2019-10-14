/*
 lab 5 additional, shortest distance between two cells in a mtrix or grid
Using DFS/BFS,  finding shortest distance between two cells in a matrix or grid.  Given a matrix of N*M order. Find the shortest distance from a source cell to a destination cell, traversing through limited cells only. Also you can move only up, down, left and right. If found output the distance else 
-1. This problem is meant for single source and destination.
*/

#include <iostream>
#include <queue> 
using namespace std; 

// QItem for current location and distance from source location 
class QItem { 
public: 
	int row; 
	int col; 
	int dist; 
	QItem(int x, int y, int w) : row(x), col(y), dist(w) 
	{ /*
		same as :
		row = x;
		col=y;
		dist=w;
	  */
	} 
}; 

int minDistance(char **grid,int N, int M) 
{ 
	QItem source(0, 0, 0); 

	// To keep track of visited QItems. Marking blocked cells as visited. 
	bool **visited = new bool*[N];
	for(int i=0; i<M; i++)
		visited[i] = new bool[M]; 
		
	for (int i = 0; i < N; i++) { 
		for (int j = 0; j < M; j++) 
		{ 
			if (grid[i][j] == '0') 
				visited[i][j] = true; 
			else
				visited[i][j] = false; 

			// Finding source 
			if (grid[i][j] == 's') 
			{ 
			source.row = i; 
			source.col = j; 
			} 
		} 
	} 

	// applying BFS on matrix cells starting from source 
	queue<QItem> q; 
	q.push(source); 
	visited[source.row][source.col] = true; 
	while (!q.empty()) { 
		QItem p = q.front(); 
		q.pop(); 

		// Destination found; 
		if (grid[p.row][p.col] == 'd') 
			return p.dist; 

		// moving up 
		if (p.row - 1 >= 0 && 
			visited[p.row - 1][p.col] == false) { 
			q.push(QItem(p.row - 1, p.col, p.dist + 1)); 
			visited[p.row - 1][p.col] = true; 
		} 

		// moving down 
		if (p.row + 1 < N && 
			visited[p.row + 1][p.col] == false) { 
			q.push(QItem(p.row + 1, p.col, p.dist + 1)); 
			visited[p.row + 1][p.col] = true; 
		} 

		// moving left 
		if (p.col - 1 >= 0 && 
			visited[p.row][p.col - 1] == false) { 
			q.push(QItem(p.row, p.col - 1, p.dist + 1)); 
			visited[p.row][p.col - 1] = true; 
		} 

		// moving right 
		if (p.col + 1 < M && 
			visited[p.row][p.col + 1] == false) { 
			q.push(QItem(p.row, p.col + 1, p.dist + 1)); 
			visited[p.row][p.col + 1] = true; 
		} 
	} 
	return -1; 
} 

int main() 
{ 
	char **grid;
	int N, M;
	cout<<"Enter number of rows :";
	cin>>N;
	cout<<"Enter number of columns :";
	cin>>M;
	grid = new char*[N];
	for(int i=0; i<M; i++)
		grid[i] = new char[M];
	
	cout<<"Enter grid :\n";
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			cin>>grid[i][j];

	cout << "Min distance : "<<minDistance(grid,N,M)<<endl; 
	return 0; 
} 

/*
OUTPUT :
Enter number of rows :4
Enter number of columns :4
Enter grid :
0 * 0 s
* 0 * *
0 * * *
d * * *
Min distance : 6

*/


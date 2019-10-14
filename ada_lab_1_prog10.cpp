/*

Using backtracking, Solve Rat in Maze problem. A Maze is given as N*N binary matrix of blocks where source block is the upper left most block i.e., maze[0][0] and destination block is lower rightmost block i.e., maze[N-1][N-1]. A rat starts from source and has to reach the destination. The rat can move only in two directions: forward and down.
In the maze matrix, 0 means the block is a dead end and 1 means the block can be used in the path from source to destination.
*/

#include <iostream>
using namespace std;

void printSolution(int **solution, int N){
	for(int i=0; i<N;i++){
		for(int j=0; j<N; j++)
			cout<<solution[i][j]<<"\t";
		cout<<endl;
	}//end of for
}//end of method

void ratMaze(int **maze, int **solution, int N, int x,int y){
	if(x==N-1 && y==N-1){
		solution[x][y] = 1;
		printSolution(solution,N);
		return;
	}//end of if
	if(x<0 || x>N-1 || y<0 || y>N-1 || maze[x][y]==0 || solution[x][y]==1) return;
	
	solution[x][y]=1;
	ratMaze(maze,solution,N,x,y+1); //right, i.e, forward
	ratMaze(maze,solution,N,x+1,y); //down
	
	
	solution[x][y]=0;
}//end of method

int main(){
	int N, **maze, **solution;
	cout<<"Enter size of matrix :";
	cin>>N;
	maze = new int*[N];
	for(int i =0; i<N; i++)
		maze[i] = new int[N];
	solution = new int*[N];
	for(int i =0; i<N; i++)
		solution[i] = new int[N];
	cout<<"Enter maze :\n";
	for(int i=0; i<N; i++)
		for(int j=0;j<N;j++)
			cin>>maze[i][j];
	ratMaze(maze,solution,N,0,0);
	return 0;
}//end of main

/*
OUTPUT:
Enter size of matrix :4
Enter maze :
1 0 0 0
1 1 0 1
0 1 0 0
1 1 1 1
1	0	0	0	
1	1	0	0	
0	1	0	0	
0	1	1	1
*/

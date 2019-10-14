/*
 A program to print the number of clusters of 1s in a binary matrix
Using DFS/BFS, Given a 2D matrix of 0s and 1s, find total number of clusters or islands formed by elements with value 1.
*/

#include<iostream> 
using namespace std;

static int rowNbr[] = {-1,-1,-1,0,0,+1,+1,+1};
static int colNbr[] = {-1,0,+1,-1,+1,-1,0,+1};

bool isSafe(int **mat, int i, int j, bool **visited, int r, int c){
	return (i>=0 && i<r && j>=0 && j<c && mat[i][j] && !visited[i][j]);
}
void DFS(int **mat, int i,int j, bool **visited, int r, int c){
	visited[i][j] = true;
	// recur for all 8 neighbours
	for(int k =0; k<8; k++){
		if(isSafe(mat,i+rowNbr[k],j+colNbr[k],visited,r,c))
			DFS(mat,i+rowNbr[k],j+colNbr[k],visited,r,c);
	}
}

int countIslands(int **mat,int r, int c){
	bool **visited = new bool *[r];
	for(int i =0; i<r; i++)
		visited[i] = new bool[c]; // visited has initial value 0
	int count =0;
	for(int i =0; i<r; i++){
		for(int j =0; j<c; j++){
			if(mat[i][j] && !visited[i][j]){
				DFS(mat,i,j,visited,r,c);
				++count;
			}
		}
	}
	return count;
}

int main(){
	int **mat,r,c;
	cout<<"Enter number of rows : ";
	cin>>r;
	cout<<"Enter number of columns : ";
	cin>>c;
	mat = new int *[r];
	for(int i =0;i<r;i++)
		mat[i] = new int[c];
		
	cout<<"Enter the matrix :\n";
	for(int i =0; i<r; i++){
		cout<<"Row "<<i<<" :\n";
		for(int j =0; j<c ;j++)
			cin>>mat[i][j];
	}
	
	cout<<"Number of clusters :"<<countIslands(mat,r,c)<<"\n";
	return 0;
}

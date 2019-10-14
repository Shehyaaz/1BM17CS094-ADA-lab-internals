/*
Using Backtracking, solve Sum of Subsets problem. Subset sum problem is to find subset of elements that are selected from a given set whose sum adds up to a given number K. We are considering the set that contains non-negative values. It is assumed that the input set is unique (no duplicates are presented) and it is given in increasing order.
Example: n=3, S=6 and W1=2, W2=4, W3=6  ; Solutions : {2, 4} and {6}
*/

#include <iostream>
using namespace std;

void sumOfSubsets(int *arr, int d, int *x, int currsum, int k, int remsum){
	//currsum : current sum ; remsum : remaining sum
	x[k] = 1; //include the kth element, this is left child in state space tree
	if(currsum + arr[k] == d){
		//subset found
		for(int i=0;i<=k;i++)
			if(x[i] == 1) cout<<arr[i]<<" ";
		cout<<endl;
		return;
	}//end of if
	else if(currsum+arr[k]+arr[k+1]<=d)
		sumOfSubsets(arr,d,x,currsum+arr[k],k+1,remsum-arr[k]);
	
	if((currsum+remsum-arr[k]>=d)&&(currsum+arr[k+1]<=d)){
		//don't include kth element, this is right child in state space tree
		x[k]=0;
		sumOfSubsets(arr,d,x,currsum, k+1,remsum-arr[k]);
	}//end of if
}//end of method

int main(){
	int n, *arr, *x, d, sum;
	cout<<"Enter number of elements :";
	cin>>n;
	arr = new int[n];
	x = new int[n];
	cout<<"Enter array elements :\n";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<"Enter the required sum :";
	cin>>d;
	for(int i=0;i<n;i++) // calcuting sum of all array elements
		sum+=arr[i];
	sumOfSubsets(arr,d,x, 0, 0, sum); // currsum =0, k=0, remsum = sum
	return 0;
}//end of main

/*
OUTPUT:
Enter number of elements :4 
Enter array elements :
5 7 8 10
Enter the required sum :15
5 10 
7 8 
*/

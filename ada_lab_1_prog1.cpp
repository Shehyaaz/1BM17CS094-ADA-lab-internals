/*
Using Quick Sort, Given an array of n numbers, the task is to answer the following queries:
Kth Smallest(start, end, k) : Find the Kth smallest number in the range from array index 'start' to 'end'.
Examples:
Input : arr[] = {3, 2, 5, 1, 8, 9}
     Query 1: start = 2, end = 5, k = 2
     Query 2: start = 1, end = 6, k = 4
Output : 2
         5
*/

#include <iostream>
using namespace std;

int Partition(int *arr, int low, int high){
	int pivot = arr[low];
	int i = low+1;
	int j = high;
	while(1){
		while(arr[i]<=pivot && i<=high) i++;
		while(arr[j]>pivot && j>=low) j--;
		if(i<j){
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}//end of if
		else{
			arr[low] = arr[j];
			arr[j] = pivot;
			return j;
		}//end of else
	}//end of loop
}//end of method

void quickSort(int *arr, int low, int high){
	if(low<high){
		int pivot_pos = Partition(arr,low,high);
		quickSort(arr,low,pivot_pos-1);
		quickSort(arr, pivot_pos+1, high);
	}//end of if
}//end of method

void kthSmallest(int *arr, int start, int end, int k){
	quickSort(arr, start, end);
	cout<<arr[start+k]<<endl;
}//end of method

int main(){
	int *arr, *arr1, n, i, start, end ,k;
	cout<<"Enter number of elements :";
	cin>>n;
	arr = new int[n];
	arr1 = new int[n];
	cout<<"Enter array elements :\n";
	for(i = 0; i<n;i++)
		cin>>arr[i];
	i = 1;
	while(1){
		cout<<"Query "<<i<<" : start, end, k :";
		cin>>start>>end>>k;
		if(start == -1 || end == -1 || k == -1) break;
		for(int j=0; j<n; j++)
			arr1[j] = arr[j];
		kthSmallest(arr1, start-1,end-1, k-1);
		i++;
	}//end of while
	return 0;
}//end of main

/*
OUTPUT :
Enter number of elements :6
Enter array elements :
3 2 5 1 8 9
Query 1 : start, end, k :2 5 2
2
Query 2 : start, end, k :1 6 4
5
Query 3 : start, end, k :3 6 1
1
Query 4 : start, end, k :3 6 3
8
Query 5 : start, end, k :5 6 2
9
Query 6 : start, end, k :-1 -1 -1
*/

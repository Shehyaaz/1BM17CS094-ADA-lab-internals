/*
lab 2 additional, searching for an element in a sorted, rotated array in O(log N) time
Using divide and conquer technique
a. Search an element in a sorted and rotated array. Program running time should be O(log n)
*/

#include <iostream>
using namespace std;

int findPivot(int *a, int low, int high){
	//base cases
	if(high < low) return -1;
	if(high == low) return low;
	
	int mid = (low+high)/2;
	if(mid<high && a[mid]>a[mid+1]) return mid;
	if(mid>low && a[mid]<a[mid-1]) return mid-1;

	if(a[low]>=a[mid]) return findPivot(a,low,mid-1);
	
	return findPivot(a,mid+1,high);
}//end of method

int binarySearch(int *a,int low,int high, int key){
	if(low > high) return -1;
	int mid = (low+high)/2;
	if (key == a[mid]) return mid;
	else if(key > a[mid]) 
		return binarySearch(a,mid+1,high,key);
	else
		return binarySearch(a,low,mid-1,key);
}//end

int main(){
	int *a,n,key;
	cout<<"Enter number of elements :";
	cin>>n;
	a = new int[n];
	cout<<"Enter elements :\n";
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<"Enter key :";
	cin>>key;
	//finding pivot
	int pivot = findPivot(a,0,n-1);
	cout<<"Pivot :"<<pivot<<"\n";
	if(key > a[0])
		cout<<key<<" found at "<<binarySearch(a,0,pivot,key)<<" index\n";
	else
		cout<<key<<" found at "<<binarySearch(a,pivot+1,n-1,key)<<" index\n";

	return 0;
}//end

/*
OUTPUT :
Enter number of elements :9
Enter elements :
5 6 7 8 9 10 1 2 3
Enter key :3
Pivot :5
3 found at 8 index
*/


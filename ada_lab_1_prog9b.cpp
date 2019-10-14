/*

Given a sorted array with repeating integers. You need to find the first occurrence , last occurrence and count of a given key in the array. Use Only  Binary Search. Your program should run in O(log N) time. If element is not present print -1 -1 0.
Input Format
First line contains N , then N integers in next line , then key in the next line.
Output Format 3 space separated integers for lower bound , upper bound and count/frequency of that key.
*/

/* A program to find first and last occurrence of a repeated element in a sprted array and also its frequency using binary search*/
#include <iostream>
#include <fstream>
using namespace std;

int firstIndex(int arr[],int n,int key){
	int beg = 0, end = n-1, mid = 0;
	while(beg<=end){
		mid = beg+(end-beg)/2;
		if((mid == 0 || key > arr[mid-1]) && key == arr[mid]) return mid;
		else if(key>arr[mid]) beg = mid+1;
		else end = mid-1;
	}
	return -1;
}

int lastIndex(int arr[],int n,int key){
	int beg = 0, end = n-1, mid = 0;
	while(beg<=end){
		mid = beg+(end - beg)/2;
		if((mid == n-1 || key < arr[mid+1]) && key == arr[mid]) return mid;
		else if(key<arr[mid]) end = mid-1;
		else beg = mid+1;
	}
	return -1;
}

int main(){
	ifstream inFile;
	//inFile.open("/home/shehyaaz/Documents/Engineering/5th Semester/ADA/ADA_Lab_internals_1_programs/test.txt");
	inFile.open("./test.txt");
	if(!inFile){
		cout<<"Something unexpected has occurred"<<endl;
		return -1;
	}
	int num, size, key, *arr;
	inFile>>num;
	for(int i=0;i<num;i++){
		inFile>>size;
		arr = new int[size];
		for(int j =0;j<size;j++) inFile>>arr[j];
		inFile>>key;
		int first = firstIndex(arr,size,key);
		int last = lastIndex(arr,size,key);
		if(first == -1 && last == -1)
			cout<<first<<" "<<last<<" "<<0<<endl;
		else
			cout<<first<<" "<<last<<" "<<(last-first+1)<<endl;
	}
	return 0;
}


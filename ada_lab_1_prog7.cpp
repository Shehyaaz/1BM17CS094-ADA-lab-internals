/*
lab 3 additional, given two sorted arrays of equal size, to find the median of the combined array in O(log N) time
Median is the middle number in a sorted list of numbers

Using Divide and Conquer technique, find the median of two sorted arrays of same size. 
The complexity of the program should be O(log(n)).
*/

#include <iostream>
#include <cmath>
using namespace std;

/* Function to get median of a sorted array */
float median(int *a, int n) 
{ 
	if (!(n&1)) // if n is even 
		return (a[n / 2] + 
				a[n / 2 - 1]) / 2; 
	else
		return a[n / 2]; 
} 

float getMedian(int *ar1, int *ar2, int n) 
{ 
	if (n <= 0) 
		return -1; 
	if (n == 1) 
		return (ar1[0] + ar2[0]) / 2; 
	if (n == 2) 
		return (max(ar1[0], ar2[0]) + 
				min(ar1[1], ar2[1])) / 2; 

	/* get the median of the first array */
	float m1 = median(ar1, n); 
	/* get the median of the second array */
	float m2 = median(ar2, n); 
	
	if (m1 == m2) 
		return m1; 

	/* if m1 < m2 then median must exist in ar1[m1....] and ar2[....m2] */
	if (m1 < m2) { 
		if (!(n&1)) 
			return getMedian(ar1 + n / 2 - 1, ar2, n - n / 2 + 1); 
		return getMedian(ar1 + n / 2, ar2, n - n / 2); 
	} 

	/* if m1 > m2 then median must exist in ar1[....m1] and ar2[m2...] */
	if (!(n&1)) 
		return getMedian(ar2 + n / 2 - 1,ar1, n - n / 2 + 1); 
	return getMedian(ar2 + n / 2,ar1, n - n / 2); 
} 

int main() {
    int *ar1, *ar2, n;
    cout<<"Enter number of elements :";
    cin>>n;
    ar1 = new int[n];
    ar2 = new int[n];
    cout<<"Enter first sorted array :\n";
    for(int i=0;i<n;i++)
    	cin>>ar1[i];
    cout<<"Enter second sorted array :\n";
    for(int i=0;i<n;i++)
    	cin>>ar2[i];
    cout<<"Median :"<<getMedian(ar1,ar2,n)<<"\n";
	return 0; 
} 
/*
OUTPUT :	
Enter number of elements :5
Enter first sorted array :
1 12 15 26 38
Enter second sorted array :
2 13 17 30 45
Median :16

*/



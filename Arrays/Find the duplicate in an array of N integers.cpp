//Find the repeating elements in a given array
/*
Approach:The elements in the array is from 0 to n-1 and all of them are positive.
So to find out the duplicate elements, a HashMap is required, but the question is to solve the problem in constant space. 
There is a catch, the array is of length n and the elements are from 0 to n-1 (n elements). The array can be used as a HashMap.

Algorithm:
Traverse the array from start to end.
For every element,take its absolute value and if the abs(array[i])‘th element is positive, the element has not encountered before,
else if negative the element has been encountered before print the absolute value of the current element.
*/
#include<bits/stdc++.h>
using namespace std;

	void printRepeating(int arr[], int size) 
	{ 
		int i; 
		for (i = 0; i < size; i++) 
		{		 
    		if (arr[abs(arr[i])] >= 0) 
    			arr[abs(arr[i])] = -arr[abs(arr[i])]; 
    		else
    			cout << abs(arr[i]) << " "; 
		} 
	}	 
  
// Driver Code 
int main() 
	{ 
    	int arr[] = {1, 2, 3, 1, 3, 6, 6,2}; 
    	int arr_size = sizeof(arr)/sizeof(arr[0]); 
    	printRepeating(arr, arr_size); 
    	return 0; 
	}	 
//Time Complexity - O(n)

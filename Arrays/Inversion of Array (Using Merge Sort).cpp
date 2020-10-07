//Inversion of Array (Using Merge Sort)
/*
Inversion Count for an array indicates – how far (or close) the array is from being sorted. If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum.
Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j

-->Approach :
Traverse through the array and for every index find the number of smaller elements on its right side of the array. 
This can be done using a nested loop. Sum up the counts for all index in the array and print the sum.

-->Algorithm :
Traverse through the array from start to end
For every element find the count of elements smaller than the current number upto that index using another loop.
Sum up the count of inversion for every index.
Print the count of inversions.
*/
#include <bits/stdc++.h> 
using namespace std; 
  
int getInvCount(int arr[], int n) 
{ 
    int inv_count = 0; 
    for (int i = 0; i < n - 1; i++) 
        for (int j = i + 1; j < n; j++) 
            if (arr[i] > arr[j]) 
                inv_count++; 
  
    return inv_count; 
} 
  
// Driver Code 
int main() 
{ 
    int arr[] = { 1, 20, 6, 4, 5 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << " Number of inversions are "
         << getInvCount(arr, n); 
    return 0; 
} 
/*
Time Complexity: O(n^2), Two nested loops are needed to traverse the array from start to end so the Time complexity is O(n^2)
Space Compelxity:O(1), No extra space is required.
*/

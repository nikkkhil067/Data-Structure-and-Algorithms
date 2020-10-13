/*
Algorithm:

1. Create a extra space, an array of length n (prefix), a variable (sum) , length (max_len) and a hash map (hm) to store sum-index pair as a key-value pair

2. Move along the input array from starting to the end

3. For every index update the value of sum = sum + array[i]

4. Check for every index, if the current sum is present in the hash map or not

5. If present update the value of max_len to maximum of difference of two indices (current index and index in the hash-map) and max_len

6. Else Put the value (sum) in the hash map, with the index as a key-value pair.

7. Print the maximum length (max_len)
*/

#include <bits/stdc++.h> 
using namespace std; 
  
// Returns Length of the required subarray 
int maxLen(int arr[], int n) 
{ 
    // Map to store the previous sums 
    unordered_map<int, int> presum; 
  
    int sum = 0; // Initialize the sum of elements 
    int max_len = 0; // Initialize result 
  
    // Traverse through the given array 
    for (int i = 0; i < n; i++) { 
        // Add current element to sum 
        sum += arr[i]; 
  
        if (arr[i] == 0 && max_len == 0) 
            max_len = 1; 
        if (sum == 0) 
            max_len = i + 1; 
  
        // Look for this sum in Hash table 
        if (presum.find(sum) != presum.end()) { 
            // If this sum is seen before, then update max_len 
            max_len = max(max_len, i - presum[sum]); 
        } 
        else { 
            // Else insert this sum with index in hash table 
            presum[sum] = i; 
        } 
    } 
  
    return max_len; 
} 
  
// Driver Code 
int main() 
{ 
    int arr[] = { 15, -2, 2, -8, 1, 7, 10, 23 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << "Length of the longest 0 sum subarray is "
         << maxLen(arr, n); 
    return 0; 
} 

/*
Time Complexity : 0(n)
Space Complexity : 0(n)
*/



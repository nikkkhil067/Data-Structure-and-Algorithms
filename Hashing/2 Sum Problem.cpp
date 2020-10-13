/*
This problem can be solved efficiently by using the technique of hashing. 
Use a hash_map to check for the current array value x(let), if there exists a value target_sum-x which on adding to the former gives target_sum. 
This can be done in constant time. 

Algorithm:
1. Initialize an empty hash table s.
2. Do following for each element A[i] in A[]
    a. If s[x – A[i]] is set then print the pair (A[i], x – A[i])
    b. Insert A[i] into s.
*/

#include <bits/stdc++.h> 
  
using namespace std; 
  
void printPairs(int arr[], int arr_size, int sum) 
{ 
    unordered_set<int> s; 
    for (int i = 0; i < arr_size; i++) { 
        int temp = sum - arr[i]; 
  
        if (s.find(temp) != s.end()) 
            cout << "Pair with given sum "
                 << sum << " is ( 
                           " << arr[i] << ", 
                "  
                    << temp << ")" << endl; 
  
        s.insert(arr[i]); 
    } 
} 
  
/* Driver program to test above function */
int main() 
{ 
    int A[] = { 1, 4, 45, 6, 10, 8 }; 
    int n = 16; 
    int arr_size = sizeof(A) / sizeof(A[0]); 
  
    // Function calling 
    printPairs(A, arr_size, n); 
  
    return 0; 
} 
/*
Time Complexity : 0(n)
Space Complexity : 0(n)
*/

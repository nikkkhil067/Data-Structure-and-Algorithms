/*
Find the largest number with given digit sum s and number of digits d

Examples:

Input  : s = 9, d = 2
Output : 90

Input  : s = 20, d = 3
Output : 992

A Simple Solution is to consider all m digit numbers 
    and keep track of maximum number with digit sum as s. 
    A close upper bound on time complexity of this solution is O(10m).

There is a Greedy approach to solve the problem. 
The idea is to one by one fill all digits from leftmost to rightmost (or from most significant digit to least significant).
We compare the remaining sum with 9 if the remaining sum is more than 9,
 we put 9 at the current position, else we put the remaining sum. 
 Since we fill digits from left to right, 
 we put the highest digits on the left side, hence get the largest number.
*/
#include <iostream> 
using namespace std; 
  
// Prints the smalles possible number with digit sum 's' 
// and 'm' number of digits. 
void findLargest(int m, int s) 
{ 
    // If sum of digits is 0, then a nuber is possible 
    // only if number of digits is 1. 
    if (s == 0) 
    { 
        (m == 1)? cout << "Largest number is " << 0 
                       : cout << "Not possible"; 
        return ; 
    } 
  
    // Sum greater than the maximum possible sum. 
    if (s > 9*m) 
    { 
        cout << "Not possible"; 
        return ; 
    } 
  
    // Create an array to store digits of result 
    int res[m]; 
  
    // Fill from most significant digit to least 
    // significant digit. 
    for (int i=0; i<m; i++) 
    { 
        // Fill 9 first to make the number largest 
        if (s >= 9) 
        { 
            res[i] = 9; 
            s -= 9; 
        } 
  
        // If remaining sum becomes less than 9, then 
        // fill the remaining sum 
        else
        { 
            res[i] = s; 
            s = 0; 
        } 
    } 
  
    cout << "Largest number is "; 
    for (int i=0; i<m; i++) 
        cout << res[i]; 
} 
  
// Driver code 
int main() 
{ 
    int s = 9, m = 2; 
    findLargest(m, s); 
    return 0; 
} 
//Time Complexity : O(m)
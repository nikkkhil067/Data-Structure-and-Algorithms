//Merge two sorted Arrays without extra space
/*
--> Approach 
1) Iterate through every element of ar2[] starting from last 
   element. Do following for every element ar2[i]
    
	a) Store last element of ar1[i]: last = ar1[i]
    
	b) Loop from last element of ar1[] while element ar1[j] is 
       smaller than ar2[i].
          ar1[j+1] = ar1[j] // Move element one position ahead
          j--
    
	c) If any element of ar1[] was moved or (j != m-1)
          ar1[j+1] = ar2[i] 
          ar2[i] = last  
*/
#include <bits/stdc++.h> 
using namespace std; 
  
// Merge ar1[] and ar2[] with O(1) extra space 
void merge(int ar1[], int ar2[], int m, int n) 
{ 
    // Iterate through all elements of ar2[] starting from 
    // the last element 
    for (int i=n-1; i>=0; i--) 
    { 
        /* Find the smallest element greater than ar2[i]. Move all 
           elements one position ahead till the smallest greater 
           element is not found */
        int j, last = ar1[m-1]; 
        for (j=m-2; j >= 0 && ar1[j] > ar2[i]; j--) 
            ar1[j+1] = ar1[j]; 
  
        // If there was a greater element 
        if (j != m-2 || last > ar2[i]) 
        { 
            ar1[j+1] = ar2[i]; 
            ar2[i] = last; 
        } 
    } 
} 
  
// Driver program 
int main(void) 
{ 
    int ar1[] = {1, 5, 9, 10, 15, 20}; 
    int ar2[] = {2, 3, 8, 13}; 
    int m = sizeof(ar1)/sizeof(ar1[0]); 
    int n = sizeof(ar2)/sizeof(ar2[0]); 
    merge(ar1, ar2, m, n); 
  
    cout << "After Merging \nFirst Array: "; 
    for (int i=0; i<m; i++) 
        cout << ar1[i] << " "; 
    cout << "\nSecond Array: "; 
    for (int i=0; i<n; i++) 
        cout << ar2[i] << " "; 
   return 0; 
}
/*Time Complexity:  O(m+n)
The worst case time complexity of code/algorithm is O(m*n). The worst case occurs when all elements of ar1[] are greater than all elements of ar2[].
*/


// C++ program for Pascal’s Triangle 
#include <bits/stdc++.h> 
using namespace std; 
  
void printPascal(int n) 
{ 
      
    // An auxiliary array to store  
    // generated pscal triangle values 
    int arr[n][n];  
  
    // Iterate through every line and  
    // print integer(s) in it 
    for (int line = 0; line < n; line++) 
    { 
        // Every line has number of integers  
        // equal to line number 
        for (int i = 0; i <= line; i++) 
        { 
        // First and last values in every row are 1 
        if (line == i || i == 0) 
            arr[line][i] = 1; 
        // Other values are sum of values just  
        // above and left of above 
        else
            arr[line][i] = arr[line - 1][i - 1] + arr[line - 1][i]; 
        cout << arr[line][i] << " "; 
        } 
        cout << "\n"; 
    } 
} 
  
// Driver code 
int main() 
{ 
    int n = 5; 
    printPascal(n); 
    return 0; 
} 
//Time Complxity - O(n^2)
//Space Complecity -  O(n^2)   

/*
Approach: 
The idea is to use Breadth First Search. 
The condition of oranges getting rotten is when they come in contact with other rotten oranges. 
This is similar to breadth-first search where the graph is divided into layers or circles and the search is done from lower or closer layers to deeper or higher layers.
In the previous approach, the idea was based on BFS but the implementation was poor and inefficient. 
To find the elements whose values are no the whole matrix had to be traversed. So that time can be reduced by using this efficient approach of BFS.

Algorithm:
1. Create an empty queue Q.
    a. Find all rotten oranges and enqueue them to Q. Also enqueue a delimiter to indicate the beginning of next time frame.
    b. Run a loop While Q is not empty
    c. Do following while delimiter in Q is not reached
    
2. Dequeue an orange from the queue, rot all adjacent oranges.
While rotting the adjacent, make sure that the time frame is incremented only once. 
And the time frame is not incremented if there are no adjacent oranges.

3. Dequeue the old delimiter and enqueue a new delimiter. The oranges rotten in the previous time frame lie between the two delimiters.
*/

#include <bits/stdc++.h> 
using namespace std; 
  
const int R = 3; 
const int C = 5; 
  
// Check if i, j is under the array limits of row and column 
bool issafe(int i, int j) 
{ 
    if (i >= 0 && i < R && j >= 0 && j < C) 
        return true; 
    return false; 
} 
  
int rotOranges(int v[R][C]) 
{ 
    bool changed = false; 
    int no = 2; 
    while (true) { 
        for (int i = 0; i < R; i++) { 
            for (int j = 0; j < C; j++) { 
  
                // Rot all other oranges present at 
                // (i+1, j), (i, j-1), (i, j+1), (i-1, j) 
                if (v[i][j] == no) { 
                    if (issafe(i + 1, j) && v[i + 1][j] == 1) { 
                        v[i + 1][j] = v[i][j] + 1; 
                        changed = true; 
                    } 
                    if (issafe(i, j + 1) && v[i][j + 1] == 1) { 
                        v[i][j + 1] = v[i][j] + 1; 
                        changed = true; 
                    } 
                    if (issafe(i - 1, j) && v[i - 1][j] == 1) { 
                        v[i - 1][j] = v[i][j] + 1; 
                        changed = true; 
                    } 
                    if (issafe(i, j - 1) && v[i][j - 1] == 1) { 
                        v[i][j - 1] = v[i][j] + 1; 
                        changed = true; 
                    } 
                } 
            } 
        } 
  
        // if no rotten orange found it means all 
        // oranges rottened now 
        if (!changed) 
            break; 
        changed = false; 
        no++; 
    } 
  
    for (int i = 0; i < R; i++) { 
        for (int j = 0; j < C; j++) { 
  
            // if any orange is found to be 
            // not rotten then ans is not possible 
            if (v[i][j] == 1) 
                return -1; 
        } 
    } 
  
    // Because initial value for a rotten 
    // orange was 2 
    return no - 2; 
} 
  
// Driver function 
int main() 
{ 
  
    int v[R][C] = { { 2, 1, 0, 2, 1 }, 
                    { 1, 0, 1, 2, 1 }, 
                    { 1, 0, 0, 2, 1 } }; 
  
    cout << "Max time incurred: " << rotOranges(v); 
  
    return 0; 
} 



/*
Time Complexity: 0( R *C)
Space Complexity: 0(R*C)
*/

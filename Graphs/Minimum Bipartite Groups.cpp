/*
Given Adjacency List representation of graph of N vertices from 1 to N, 
    the task is to count the minimum bipartite groups of the given graph.

    Example : 
    Input: N = 5
    Below is the given graph with number of nodes is 5:

             2      5
          /   \
        1      3
                \
                 4
    
    Output: 3
    Explanation:
    Possible groups satisfying the Bipartite property: [2, 5], [1, 3], [4]

The idea is to find the maximum height of all the Connected Components in the given graph of N nodes 
    to find the minimum bipartite groups. 
Below are the steps:

1. For all the non-visited vertex in the given graph, 
    find the height of the current Connected Components starting from the current vertex.

2. Start DFS Traversal to find the height of all the Connected Components.
3. The maximum of the heights calculated for all the Connected Components 
    gives the minimum bipartite groups required.
*/

#include <bits/stdc++.h> 
using namespace std; 
  
// Function to find the height sizeof 
// the current component with vertex s 
int height(int s, vector<int> adj[], 
           int* visited) 
{ 
    // Visit the current Node 
    visited[s] = 1; 
    int h = 0; 
  
    // Call DFS recursively to find the 
    // maximum height of current CC 
    for (auto& child : adj[s]) { 
  
        // If the node is not visited 
        // then the height recursively 
        // for next element 
        if (visited[child] == 0) { 
            h = max(h, 1 + height(child, adj, 
                                  visited)); 
        } 
    } 
    return h; 
} 
  
// Function to find the minimum Groups 
int minimumGroups(vector<int> adj[], int N) 
{ 
    // Intialise with visited array 
    int visited[N + 1] = { 0 }; 
  
    // To find the minimum groups 
    int groups = INT_MIN; 
  
    // Traverse all the non visited Node 
    // and calculate the height of the 
    // tree with current node as a head 
    for (int i = 1; i <= N; i++) { 
  
        // If the current is not visited 
        // therefore, we get another CC 
        if (visited[i] == 0) { 
            int comHeight; 
            comHeight = height(i, adj, visited); 
            groups = max(groups, comHeight); 
        } 
    } 
  
    // Return the minimum bipartite matching 
    return groups; 
} 
  
// Function that adds the current edges 
// in the given graph 
void addEdge(vector<int> adj[], int u, int v) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 
  
// Drivers Code 
int main() 
{ 
    int N = 5; 
  
    // Adjacency List 
    vector<int> adj[N + 1]; 
  
    // Adding edges to List 
    addEdge(adj, 1, 2); 
    addEdge(adj, 3, 2); 
    addEdge(adj, 4, 3); 
  
    cout << minimumGroups(adj, N); 
} 

//Time Complexity : O(V+E), where V is the number of vertices and E is the set of edges.
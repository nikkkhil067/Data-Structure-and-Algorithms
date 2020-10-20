/*
Topological sorting for Directed Acyclic Graph (DAG) is a 
linear ordering of vertices such that for every directed edge u v, 
vertex u comes before v in the ordering. 
Topological Sorting for a graph is not possible if the graph is not a DAG.

For example, a topological sorting of the following graph is “5 4 2 3 1 0”. 
There can be more than one topological sorting for a graph. 
For example, another topological sorting of the following graph is “4 5 2 3 1 0”. 
The first vertex in topological sorting is always a vertex with in-degree as 0 (a vertex with no incoming edges).

In DFS, we print a vertex and then recursively call DFS for its adjacent vertices. 
In topological sorting, we need to print a vertex before its adjacent vertices. 
For example, in the given graph, the vertex ‘5’ should be printed before vertex ‘0’,
 but unlike DFS, the vertex ‘4’ should also be printed before vertex ‘0’. 
 So Topological sorting is different from DFS. 
 For example, a DFS of the shown graph is “5 2 3 1 0 4”, but it is not a topological sorting.


Algorithm to find Topological Sorting: 
In DFS, we start from a vertex, we first print it and then recursively call DFS for its adjacent vertices.
 In topological sorting, we use a temporary stack. 
 We don’t print the vertex immediately, 
 we first recursively call topological sorting for all its adjacent vertices,
then push it to a stack. 
  Finally, print contents of the stack. 
Note that a vertex is pushed to stack only when all of its adjacent vertices (and their adjacent vertices and so on) are already in the stack. 
*/

#include <iostream> 
#include <list> 
#include <stack> 
using namespace std; 
  
// Class to represent a graph 
class Graph { 
    // No. of vertices' 
    int V; 
  
    // Pointer to an array containing adjacency listsList 
    list<int>* adj; 
  
    // A function used by topologicalSort 
    void topologicalSortUtil(int v, bool visited[], 
                             stack<int>& Stack); 
  
public: 
    // Constructor 
    Graph(int V); 
  
    // function to add an edge to graph 
    void addEdge(int v, int w); 
  
    // prints a Topological Sort of 
    // the complete graph 
    void topologicalSort(); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    // Add w to v’s list. 
    adj[v].push_back(w); 
} 
  
// A recursive function used by topologicalSort 
void Graph::topologicalSortUtil(int v, bool visited[], 
                                stack<int>& Stack) 
{ 
    // Mark the current node as visited. 
    visited[v] = true; 
  
    // Recur for all the vertices 
    // adjacent to this vertex 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            topologicalSortUtil(*i, visited, Stack); 
  
    // Push current vertex to stack 
    // which stores result 
    Stack.push(v); 
} 
  
// The function to do Topological Sort. 
// It uses recursive topologicalSortUtil() 
void Graph::topologicalSort() 
{ 
    stack<int> Stack; 
  
    // Mark all the vertices as not visited 
    bool* visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Call the recursive helper function 
    // to store Topological 
    // Sort starting from all 
    // vertices one by one 
    for (int i = 0; i < V; i++) 
        if (visited[i] == false) 
            topologicalSortUtil(i, visited, Stack); 
  
    // Print contents of stack 
    while (Stack.empty() == false) { 
        cout << Stack.top() << " "; 
        Stack.pop(); 
    } 
} 
  
// Driver Code 
int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(6); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 
  
    cout << "Following is a Topological Sort of the given "
            "graph \n"; 
    
    // Function Call 
    g.topologicalSort(); 
  
    return 0; 
}

/*
Output
Following is a Topological Sort of the given graph 
5 4 2 3 1 0 

Time Complexity: O(V+E). 
    The above algorithm is simply DFS with an extra stack. So time complexity is the same as DFS which is.

Auxiliary space: O(V). 
    The extra space is needed for the stack.

Applications: 

Topological Sorting is mainly used for scheduling jobs from the given dependencies among jobs.
In computer science, applications of this type arise in instruction scheduling, 
ordering of formula cell evaluation when recomputing formula values in spreadsheets, 
logic synthesis, determining the order of compilation tasks to perform in make files,
data serialization, and resolving symbol dependencies in linkers
*/


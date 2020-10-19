/*
Approach:
The problem can also be solved using simple recursive traversal. 
We can keep track of the level of a node by passing a parameter to all recursive calls. 
The idea is to keep track of the maximum level also. 
Whenever we see a node whose level is more than maximum level so far, we print the node because this is the first node in its level 
(Note that we traverse the left subtree before right subtree). 
*/
#include <bits/stdc++.h> 
using namespace std; 
  
class node { 
public: 
    int data; 
    node *left, *right; 
}; 
  
// A utility function to create a new Binary Tree node 
node* newNode(int item) 
{ 
    node* temp = new node(); 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
// Recursive function to print left view of a binary tree. 
void leftViewUtil(node* root, int level, int* max_level) 
{ 
    // Base Case 
    if (root == NULL) 
        return; 
  
    // If this is the first node of its level 
    if (*max_level < level) { 
        cout << root->data << "\t"; 
        *max_level = level; 
    } 
  
    // Recur for left and right subtrees 
    leftViewUtil(root->left, level + 1, max_level); 
    leftViewUtil(root->right, level + 1, max_level); 
} 
  
// A wrapper over leftViewUtil() 
void leftView(node* root) 
{ 
    int max_level = 0; 
    leftViewUtil(root, 1, &max_level); 
} 
  
// Driver code 
int main() 
{ 
    node* root = newNode(12); 
    root->left = newNode(10); 
    root->right = newNode(30); 
    root->right->left = newNode(25); 
    root->right->right = newNode(40); 
  
    leftView(root); 
  
    return 0; 
} 
/*
Time Complexity : 0(n)
Space Complexity: 0(n)
*/

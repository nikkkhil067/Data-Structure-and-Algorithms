/*
Algorithm:
1. If tree is empty then return 0
2. Else
     (a) Get the max depth of left subtree recursively  i.e., 
          call maxDepth( tree->left-subtree)
     (a) Get the max depth of right subtree recursively  i.e., 
          call maxDepth( tree->right-subtree)
     (c) Get the max of max depths of left and right 
          subtrees and add 1 to it for the current node.
         max_depth = max(max dept of left subtree,  
                             max depth of right subtree) 
                             + 1
     (d) Return max_depth
*/

#include <bits/stdc++.h> 
using namespace std; 
  
  
/* A binary tree node has data, pointer to left child 
and a pointer to right child */
class node  
{  
    public: 
    int data;  
    node* left;  
    node* right;  
};  
  
/* Compute the "maxDepth" of a tree -- the number of  
    nodes along the longest path from the root node  
    down to the farthest leaf node.*/
int maxDepth(node* node)  
{  
    if (node == NULL)  
        return 0;  
    else
    {  
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);  
        int rDepth = maxDepth(node->right);  
      
        /* use the larger one */
        if (lDepth > rDepth)  
            return(lDepth + 1);  
        else return(rDepth + 1);  
    }  
}  
  
/* Helper function that allocates a new node with the  
given data and NULL left and right pointers. */
node* newNode(int data)  
{  
    node* Node = new node(); 
    Node->data = data;  
    Node->left = NULL;  
    Node->right = NULL;  
      
    return(Node);  
}  
      
// Driver code     
int main()  
{  
    node *root = newNode(1);  
  
    root->left = newNode(2);  
    root->right = newNode(3);  
    root->left->left = newNode(4);  
    root->left->right = newNode(5);  
      
    cout << "Height of tree is " << maxDepth(root);  
    return 0;  
}  
//Time Complexity : 0(n)

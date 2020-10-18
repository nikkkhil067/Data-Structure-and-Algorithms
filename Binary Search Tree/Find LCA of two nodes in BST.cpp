/*
Algorithm:

1. Create a recursive function that takes a node and the two values n1 and n2.
2. If the value of the current node is less than both n1 and n2, then LCA lies in the right subtree. Call the recursive function for thr right subtree.
3. If the value of the current node is greater than both n1 and n2, then LCA lies in the left subtree. Call the recursive function for thr left subtree.
4. If both the above cases are false then return the current node as LCA.
*/

#include <bits/stdc++.h> 
using namespace std; 
  
class node  
{  
    public: 
    int data;  
    node* left, *right;  
};  
  
/* Function to find LCA of n1 and n2.  
The function assumes that both  
n1 and n2 are present in BST */
node *lca(node* root, int n1, int n2)  
{  
    if (root == NULL) return NULL;  
  
    // If both n1 and n2 are smaller 
    // than root, then LCA lies in left  
    if (root->data > n1 && root->data > n2)  
        return lca(root->left, n1, n2);  
  
    // If both n1 and n2 are greater than  
    // root, then LCA lies in right  
    if (root->data < n1 && root->data < n2)  
        return lca(root->right, n1, n2);  
  
    return root;  
}  
  
/* Helper function that allocates  
a new node with the given data.*/
node* newNode(int data)  
{  
    node* Node = new node(); 
    Node->data = data;  
    Node->left = Node->right = NULL;  
    return(Node);  
}  
  
/* Driver code*/
int main()  
{  
    // Let us construct the BST  
    // shown in the above figure  
    node *root = newNode(20);  
    root->left = newNode(8);  
    root->right = newNode(22);  
    root->left->left = newNode(4);  
    root->left->right = newNode(12);  
    root->left->right->left = newNode(10);  
    root->left->right->right = newNode(14);  
  
    int n1 = 10, n2 = 14;  
    node *t = lca(root, n1, n2);  
    cout << "LCA of " << n1 << " and " << n2 << " is " << t->data<<endl;  
  
    n1 = 14, n2 = 8;  
    t = lca(root, n1, n2);  
    cout<<"LCA of " << n1 << " and " << n2 << " is " << t->data << endl;  
  
    n1 = 10, n2 = 22;  
    t = lca(root, n1, n2);  
    cout << "LCA of " << n1 << " and " << n2 << " is " << t->data << endl;  
    return 0;  
} 

/*
Time Complexity: O(h).
The time Complexity of the above solution is O(h), where h is the height of the tree.
Space Complexity: O(1).
If recursive stack space is ignored, the space complexity of the above solution is constant.
*/

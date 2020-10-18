#include <bits/stdc++.h> 
using namespace std; 
  
/*Structure of each Node in the tree*/
struct Node { 
    int data; 
    Node *left, *right; 
}; 
  
/*This function is used to create and 
initializes new Nodes*/
Node* newNode(int key) 
{ 
    Node* temp = new Node; 
    temp->left = temp->right = NULL; 
    temp->data = key; 
    return temp; 
} 
  
/* This function is used to insert 
 new values in BST*/
Node* insert(Node* root, int key) 
{ 
    if (!root) 
        return newNode(key); 
    if (key < root->data) 
        root->left = insert(root->left, key); 
    else
        root->right = insert(root->right, key); 
    return root; 
} 
  
/*This function is used to find floor of a key*/
int floor(Node* root, int key) 
{ 
    if (!root) 
        return INT_MAX; 
  
    /* If root->data is equal to key */
    if (root->data == key) 
        return root->data; 
  
    /* If root->data is greater than the key */
    if (root->data > key) 
        return floor(root->left, key); 
  
    /* Else, the floor may lie in right subtree 
      or may be equal to the root*/
    int floorValue = floor(root->right, key); 
    return (floorValue <= key) ? floorValue : root->data; 
} 
  
int main() 
{ 
    /* Let us create following BST 
              7 
            /    \ 
           5      10 
         /  \    /  \ 
        3    6   8   12 
        Output :Floor of 9 =  8 */
    Node* root = NULL; 
    root = insert(root, 7); 
    insert(root, 10); 
    insert(root, 5); 
    insert(root, 3); 
    insert(root, 6); 
    insert(root, 8); 
    insert(root, 12); 
    cout << floor(root, 9) << endl; 
    return 0; 
}
//Time Complexity : 0(h)

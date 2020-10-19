/*
Approach:
A pre-order traversal of the binary tree using stack has been implied in this approach. 
In this traversal, every time a right child is pushed in the stack, the right child is made equal to the left child and left child is made equal to NULL.
If the right child of the node becomes NULL, the stack is popped and the right child becomes the popped value from the stack. 
The above steps are repeated until the size of the stack is zero or root is NULL.
*/

#include <iostream> 
#include <stack> 
using namespace std; 
  
struct Node { 
    int key; 
    Node *left, *right; 
}; 
  
/* utility that allocates a new Node  
   with the given key  */
Node* newNode(int key) 
{ 
    Node* node = new Node; 
    node->key = key; 
    node->left = node->right = NULL; 
    return (node); 
} 
  
// To find the inorder traversal 
void inorder(struct Node* root) 
{ 
    // base condition 
    if (root == NULL) 
        return; 
    inorder(root->left); 
    cout << root->key << " "; 
    inorder(root->right); 
} 
  
// Function to convert binary tree into 
// linked list by altering the right node 
// and making left node point to NULL 
Node* solution(Node* A) 
{ 
  
    // Declare a stack 
    stack<Node*> st; 
    Node* ans = A; 
  
    // Iterate till the stack is not empty 
    // and till root is Null 
    while (A != NULL || st.size() != 0) { 
  
        // Check for NULL 
        if (A->right != NULL) { 
            st.push(A->right); 
        } 
  
        // Make the Right Left and 
        // left NULL 
        A->right = A->left; 
        A->left = NULL; 
  
        // Check for NULL 
        if (A->right == NULL && st.size() != 0) { 
            A->right = st.top(); 
            st.pop(); 
        } 
  
        // Iterate 
        A = A->right; 
    } 
    return ans; 
} 
  
// Driver Code 
int main() 
{ 
    /*    1 
        /   \ 
       2     5 
      / \     \ 
     3   4     6 */
  
    // Build the tree 
    Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(5); 
    root->left->left = newNode(3); 
    root->left->right = newNode(4); 
    root->right->right = newNode(6); 
  
    // Call the function to 
    // flatten the tree 
    root = solution(root); 
  
    cout << "The Inorder traversal after "
            "flattening binary tree "; 
  
    // call the function to print 
    // inorder after flatenning 
    inorder(root); 
    return 0; 
} 
/*
Time Complexity: O(N)
Auxiliary Space: O(Log N)
*/

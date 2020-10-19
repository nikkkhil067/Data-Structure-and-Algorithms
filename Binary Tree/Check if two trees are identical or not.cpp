/*
Algorithm:
1. If both trees are empty then return 1.
2. Else If both trees are non -empty
     (a) Check data of the root nodes (tree1->data ==  tree2->data)
     (b) Check left subtrees recursively  i.e., call sameTree( 
          tree1->left_subtree, tree2->left_subtree)
     (c) Check right subtrees recursively  i.e., call sameTree( 
          tree1->right_subtree, tree2->right_subtree)
     (d) If a,b and c are true then return 1.
3  Else return 0 (one is empty and other is not)
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
  
/* Given two trees, return true if they are  
structurally identical */
int identicalTrees(node* a, node* b)  
{  
    /*1. both empty */
    if (a == NULL && b == NULL)  
        return 1;  
  
    /* 2. both non-empty -> compare them */
    if (a != NULL && b != NULL)  
    {  
        return
        (  
            a->data == b->data &&  
            identicalTrees(a->left, b->left) &&  
            identicalTrees(a->right, b->right)  
        );  
    }  
      
    /* 3. one empty, one not -> false */
    return 0;  
}  
  
/* Driver code*/
int main()  
{  
    node *root1 = newNode(1);  
    node *root2 = newNode(1);  
    root1->left = newNode(2);  
    root1->right = newNode(3);  
    root1->left->left = newNode(4);  
    root1->left->right = newNode(5);  
  
    root2->left = newNode(2);  
    root2->right = newNode(3);  
    root2->left->left = newNode(4);  
    root2->left->right = newNode(5);  
  
    if(identicalTrees(root1, root2))  
        cout << "Both tree are identical.";  
    else
        cout << "Trees are not identical.";  
  
return 0;  
}  

/*
Time Complexity: Complexity of the identicalTree() will be according to the tree with lesser number of nodes.
Let number of nodes in two trees be m and n then complexity of sameTree() is O(m) where m < n.
*/

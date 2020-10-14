/*
Approach: The recursive solution can be formed, given the linked lists are sorted.

1. Compare the head of both linked lists.

2. Find the smaller node among the two head nodes. The current element will be the smaller node among two head nodes.

3. The rest elements of both lists will appear after that.

4. Now run a recursive function with parameters, the next node of the smaller element and the other head.

5. The recursive function will return the next smaller element linked with rest of the sorted element. 
    Now point the next of current element to that, i.e curr_ele->next=recursivefunction()
    
6. Handle some corner cases.
i)  If both the heads are NULL return null.
ii) If one head is null return the other.
*/


#include <bits/stdc++.h> 
using namespace std; 
  
struct Node { 
    int data; 
    struct Node* next; 
}; 
  
// Function to create newNode in a linkedlist 
Node* newNode(int key) 
{ 
    struct Node* temp = new Node; 
    temp->data = key; 
    temp->next = NULL; 
    return temp; 
} 
  
// A utility function to print linked list 
void printList(Node* node) 
{ 
    while (node != NULL) { 
        printf("%d  ", node->data); 
        node = node->next; 
    } 
} 
  
// Merges two given lists in-place. This function 
// mainly compares head nodes and calls mergeUtil() 
Node* merge(Node* h1, Node* h2) 
{ 
    if (!h1) 
        return h2; 
    if (!h2) 
        return h1; 
  
    // start with the linked list 
    // whose head data is the least 
    if (h1->data < h2->data) { 
        h1->next = merge(h1->next, h2); 
        return h1; 
    } 
    else { 
        h2->next = merge(h1, h2->next); 
        return h2; 
    } 
} 
  
// Driver program 
int main() 
{ 
    Node* head1 = newNode(1); 
    head1->next = newNode(3); 
    head1->next->next = newNode(5); 
  
    // 1->3->5 LinkedList created 
  
    Node* head2 = newNode(0); 
    head2->next = newNode(2); 
    head2->next->next = newNode(4); 
  
    // 0->2->4 LinkedList created 
  
    Node* mergedhead = merge(head1, head2); 
  
    printList(mergedhead); 
    return 0; 
}

/*
Time Complexity : 0(n)
Auxiliary Space : 0(n)
*/

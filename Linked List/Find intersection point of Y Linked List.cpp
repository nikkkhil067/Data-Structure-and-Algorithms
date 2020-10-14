/*
Approach: 
It can be observed that the number of nodes in traversing the first linked list
and then from the head of the second linked list to intersection point is equal
to the number of nodes involved in traversing the second linked list and then from head of the first list to the intersection point. 
Start traversing the two linked lists with two pointers curr1 and curr2 pointing to the heads of the given linked lists respectively.

1. If curr1 != null then update it to point to the next node, else it is updated to point to the first node of the second list.
2. If curr2 != null then update it to point to the next node, else it is updated to point to the first node of the first list.
3. Repeat the above steps while curr1 is not equal to curr2.

The two pointers curr1 and curr2 will be pointing to the same node now i.e. the merging point.
*/
#include <iostream> 
using namespace std; 
  
// Link list node 
struct Node { 
    int data; 
    Node* next; 
}; 
  
// Function to get the intersection point 
// of the given linked lists 
int getIntersectionNode(Node* head1, Node* head2) 
{ 
    Node *curr1 = head1, *curr2 = head2; 
  
    // While both the pointers are not equal 
    while (curr1 != curr2) { 
  
        // If the first pointer is null then 
        // set it to point to the head of 
        // the second linked list 
        if (curr1 == NULL) { 
            curr1 = head2; 
        } 
  
        // Else point it to the next node 
        else { 
            curr1 = curr1->next; 
        } 
  
        // If the second pointer is null then 
        // set it to point to the head of 
        // the first linked list 
        if (curr2 == NULL) { 
            curr2 = head1; 
        } 
  
        // Else point it to the next node 
        else { 
            curr2 = curr2->next; 
        } 
    } 
  
    // Return the intersection node 
    return curr1->data; 
} 
  
// Driver code 
int main() 
{ 
    /* 
    Create two linked lists 
  
    1st Linked list is 3->6->9->15->30 
    2nd Linked list is 10->15->30 
      
    15 is the intersection point 
    */
  
    Node* newNode; 
    Node* head1 = new Node(); 
    head1->data = 10; 
    Node* head2 = new Node(); 
    head2->data = 3; 
    newNode = new Node(); 
    newNode->data = 6; 
    head2->next = newNode; 
    newNode = new Node(); 
    newNode->data = 9; 
    head2->next->next = newNode; 
    newNode = new Node(); 
    newNode->data = 15; 
    head1->next = newNode; 
    head2->next->next->next = newNode; 
    newNode = new Node(); 
    newNode->data = 30; 
    head1->next->next = newNode; 
    head1->next->next->next = NULL; 
  
    // Print the intersection node 
    cout << getIntersectionNode(head1, head2); 
  
    return 0; 
} 

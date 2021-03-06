/*
Given a linked list having two pointers in each node. 
The first one points to the next node of the list, however, the other pointer is random and can point to any node of the list. 
Write a program that clones the given list in O(1) space, i.e., without any extra space.

Approach:
1. Create the copy of node 1 and insert it between node 1 & node 2 in original Linked List, create a copy of 2 and insert it between 2 & 3. 
Continue in this fashion, add the copy of N after the Nth node
2. Now copy the random link in this fashion
 original->next->random= original->random->next;  /*TRAVERSE TWO NODES*/
This works because original->next is nothing but copy of original and Original->random->next is nothing but copy of random.
3. Now restore the original and copy linked lists in this fashion in a single loop.
     original->next = original->next->next;
     copy->next = copy->next->next;
4. Ensure that original->next is NULL and return the cloned list 
*/

// C++ program to clone a linked list with next 
// and arbit pointers in O(n) time 
#include <bits/stdc++.h> 
using namespace std; 

// Structure of linked list Node 
struct Node 
{ 
	int data; 
	Node *next,*random; 
	Node(int x) 
	{ 
		data = x; 
		next = random = NULL; 
	} 
}; 

// Utility function to print the list. 
void print(Node *start) 
{ 
	Node *ptr = start; 
	while (ptr) 
	{ 
		cout << "Data = " << ptr->data << ", Random = "
			<< ptr->random->data << endl; 
		ptr = ptr->next; 
	} 
} 

// This function clones a given linked list 
// in O(1) space 
Node* clone(Node *start) 
{ 
	Node* curr = start, *temp; 

	// insert additional node after 
	// every node of original list 
	while (curr) 
	{ 
		temp = curr->next; 

		// Inserting node 
		curr->next = new Node(curr->data); 
		curr->next->next = temp; 
		curr = temp; 
	} 

	curr = start; 

	// adjust the random pointers of the 
	// newly added nodes 
	while (curr) 
	{ 
		if(curr->next) 
			curr->next->random = curr->random ? 
								curr->random->next : curr->random; 

		// move to the next newly added node by 
		// skipping an original node 
		curr = curr->next?curr->next->next:curr->next; 
	} 

	Node* original = start, *copy = start->next; 

	// save the start of copied linked list 
	temp = copy; 

	// now separate the original list and copied list 
	while (original && copy) 
	{ 
		original->next = 
		original->next? original->next->next : original->next; 

		copy->next = copy->next?copy->next->next:copy->next; 
		original = original->next; 
		copy = copy->next; 
	} 

	return temp; 
} 

// Driver code 
int main() 
{ 
	Node* start = new Node(1); 
	start->next = new Node(2); 
	start->next->next = new Node(3); 
	start->next->next->next = new Node(4); 
	start->next->next->next->next = new Node(5); 

	// 1's random points to 3 
	start->random = start->next->next; 

	// 2's random points to 1 
	start->next->random = start; 

	// 3's and 4's random points to 5 
	start->next->next->random = 
					start->next->next->next->next; 
	start->next->next->next->random = 
					start->next->next->next->next; 

	// 5's random points to 2 
	start->next->next->next->next->random = 
									start->next; 

	cout << "Original list : \n"; 
	print(start); 

	cout << "\nCloned list : \n"; 
	Node *cloned_list = clone(start); 
	print(cloned_list); 

	return 0; 
} 

/*
Recursive Approach: 
Use two pointers left and right. Move right and left using recursion and check for following in each recursive call.
1) Sub-list is palindrome.
2) Value at current left and right are matching.

If both above conditions are true then return true.

The idea is to use function call stack as container. 
Recursively traverse till the end of list. 
When we return from last NULL, we will be at last node. 
The last node to be compared with first node of list.

In order to access first node of list, we need list head to be available in the last call of recursion.
Hence we pass head also to the recursive function. 
If they both match we need to compare (2, n-2) nodes. 
Again when recursion falls back to (n-2)nd node, we need reference to 2nd node from head. 
We advance the head pointer in previous call, to refer to next node in the list.

However, the trick in identifying double pointer. 
Passing single pointer is as good as pass-by-value, and we will pass the same pointer again and again. 
We need to pass the address of head pointer for reflecting the changes in parent recursive calls.
*/

/* Link list node */
struct node { 
	char data; 
	struct node* next; 
}; 

// Initial parameters to this function are &head and head 
bool isPalindromeUtil(struct node** left, struct node* right) 
{ 
	/* stop recursion when right becomes NULL */
	if (right == NULL) 
		return true; 

	/* If sub-list is not palindrome then no need to 
	check for current left and right, return false */
	bool isp = isPalindromeUtil(left, right->next); 
	if (isp == false) 
		return false; 

	/* Check values at current left and right */
	bool isp1 = (right->data == (*left)->data); 

	/* Move left to next node */
	*left = (*left)->next; 

	return isp1; 
} 

// A wrapper over isPalindromeUtil() 
bool isPalindrome(struct node* head) 
{ 
	isPalindromeUtil(&head, head); 
} 

/* Push a node to linked list. Note that this function 
changes the head */
void push(struct node** head_ref, char new_data) 
{ 
	/* allocate node */
	struct node* new_node = (struct node*)malloc(sizeof(struct node)); 

	/* put in the data */
	new_node->data = new_data; 

	/* link the old list off the new node */
	new_node->next = (*head_ref); 

	/* move the head to pochar to the new node */
	(*head_ref) = new_node; 
} 

// A utility function to print a given linked list 
void printList(struct node* ptr) 
{ 
	while (ptr != NULL) { 
		cout << ptr->data << "->"; 
		ptr = ptr->next; 
	} 
	cout << "NULL\n" ; 
} 

/* Driver program to test above function*/
int main() 
{ 
	/* Start with the empty list */
	struct node* head = NULL; 
	char str[] = "abacaba"; 
	int i; 

	for (i = 0; str[i] != '\0'; i++) { 
		push(&head, str[i]); 
		printList(head); 
		isPalindrome(head) ? cout << "Is Palindrome\n\n" : cout << "Not Palindrome\n\n"; 
	} 

	return 0; 
} 

/*
Time Complexity : 0(n)
Space Complexity : 0(n)
*/

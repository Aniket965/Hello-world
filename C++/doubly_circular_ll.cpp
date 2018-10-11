// C++ program to illustrate inserting a Node in 
// a Cicular Doubly Linked list in begging, end 
// and middle 
#include <bits/stdc++.h> 
using namespace std; 

// Structure of a Node 
struct Node 
{ 
	int data; 
	struct Node *next; 
	struct Node *prev; 
}; 

// Function to insert at the end 
void insertEnd(struct Node** start, int value) 
{ 
	// If the list is empty, create a single node 
	// circular and doubly list 
	if (*start == NULL) 
	{ 
		struct Node* new_node = new Node; 
		new_node->data = value; 
		new_node->next = new_node->prev = new_node; 
		*start = new_node; 
		return; 
	} 

	// If list is not empty 

	/* Find last node */
	Node *last = (*start)->prev; 

	// Create Node dynamically 
	struct Node* new_node = new Node; 
	new_node->data = value; 

	// Start is going to be next of new_node 
	new_node->next = *start; 

	// Make new node previous of start 
	(*start)->prev = new_node; 

	// Make last preivous of new node 
	new_node->prev = last; 

	// Make new node next of old last 
	last->next = new_node; 
} 

// Function to insert Node at the beginning 
// of the List, 
void insertBegin(struct Node** start, int value) 
{ 
	// Pointer points to last Node 
	struct Node *last = (*start)->prev; 

	struct Node* new_node = new Node; 
	new_node->data = value; // Inserting the data 

	// setting up previous and next of new node 
	new_node->next = *start; 
	new_node->prev = last; 

	// Update next and previous pointers of start 
	// and last. 
	last->next = (*start)->prev = new_node; 

	// Update start pointer 
	*start = new_node; 
} 

// Function to insert node with value as value1. 
// The new node is inserted after the node with 
// with value2 
void insertAfter(struct Node** start, int value1, 
									int value2) 
{ 
	struct Node* new_node = new Node; 
	new_node->data = value1; // Inserting the data 

	// Find node having value2 and next node of it 
	struct Node *temp = *start; 
	while (temp->data != value2) 
		temp = temp->next; 
	struct Node *next = temp->next; 

	// insert new_node between temp and next. 
	temp->next = new_node; 
	new_node->prev = temp; 
	new_node->next = next; 
	next->prev = new_node; 
} 


void display(struct Node* start) 
{ 
	struct Node *temp = start; 

	printf("\nTraversal in forward direction \n"); 
	while (temp->next != start) 
	{ 
		printf("%d ", temp->data); 
		temp = temp->next; 
	} 
	printf("%d ", temp->data); 

	printf("\nTraversal in reverse direction \n"); 
	Node *last = start->prev; 
	temp = last; 
	while (temp->prev != last) 
	{ 
		printf("%d ", temp->data); 
		temp = temp->prev; 
	} 
	printf("%d ", temp->data); 
} 

/* Driver program to test above functions*/
int main() 
{ 
	/* Start with the empty list */
	struct Node* start = NULL; 

	// Insert 5. So linked list becomes 5->NULL 
	insertEnd(&start, 5); 

	// Insert 4 at the beginning. So linked 
	// list becomes 4->5 
	insertBegin(&start, 4); 

	// Insert 7 at the end. So linked list 
	// becomes 4->5->7 
	insertEnd(&start, 7); 

	// Insert 8 at the end. So linked list 
	// becomes 4->5->7->8 
	insertEnd(&start, 8); 

	// Insert 6, after 5. So linked list 
	// becomes 4->5->6->7->8 
	insertAfter(&start, 6, 5); 

	printf("Created circular doubly linked list is: "); 
	display(start); 

	return 0; 
} 

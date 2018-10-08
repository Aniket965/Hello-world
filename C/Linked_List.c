#include <stdio.h>
#include <stdlib.h>

//-------------------------------------------------------------------------------------
// CONSTANTS and TYPES
//-------------------------------------------------------------------------------------

struct Node {
  int data;
  struct Node *next;
};

struct linkedList {
  int size;
  struct Node *top;
};

typedef struct linkedList *LinkedList;
typedef struct Node *Node;

//-------------------------------------------------------------------------------------
// PROTOTYPES
//-------------------------------------------------------------------------------------

LinkedList newList();
LinkedList addNode(LinkedList list, int value);
int getNode(LinkedList list, int pos);
LinkedList removeNode(LinkedList list, int pos);
void printList(LinkedList list);

//-------------------------------------------------------------------------------------
// FUNCTIONS
//-------------------------------------------------------------------------------------

int main(int numParms, char *parms[]){

  //create a new linked list
  LinkedList myList;
  myList = newList();

  //Add test values to list and print it
  myList = addNode(myList, 4);
  printList(myList);

  myList = addNode(myList, 3);
  printList(myList);

  myList = addNode(myList, 1);
  myList = addNode(myList, 5);
  myList = addNode(myList, 7);
  printList(myList);

  myList = removeNode(myList, 3);
  myList = removeNode(myList, 2);
  myList = removeNode(myList, 1);
  printList(myList);

  printf("End of program.\n");

  return 0;

}

LinkedList newList(){

  LinkedList list;

  //Allocate memory in heap to the list
  list = (LinkedList) malloc(sizeof(struct linkedList));
  //Initalize the list by setting the top node to NULL and size to 0
  list -> top = NULL;
  list -> size = 0;

  return list;
}

LinkedList addNode(LinkedList list, int value){

  Node newNode;

  //Allocate memory in heap to the node
  newNode = (Node) malloc(sizeof(Node));
  //Asign value to newNode.data
  newNode -> data = value;
  //Set the next node for the newNode as the current top of the list
  newNode -> next = list -> top;

  //Set the top of the list to newNode and increase the size of the list
  list -> top = newNode;
  list -> size++;

  return list;
}

int getNode(LinkedList list, int pos){

  int entry;
  int count;
  Node current;

  //Select the the node at the top of the list as our first node
  current = list->top;

  //Keep selecting the next node till we get to our desired position
  for(count=0; count<pos; count++){
    current = current -> next;
  }

  //Get the value of the node and return it
  entry = current -> data;
  return entry;

}

LinkedList removeNode(LinkedList list, int pos){
  int count;
  Node current;
  Node previous;

  //Start the search from the top of the list
  previous = NULL;
  current = list -> top;
  //Loop throug the list till we reach the position our node is in. Keep selecting
  //the next node while also keeping track of the previous node
  for(count=0; count<pos; count++){
    previous = current;
    current = current -> next;
  }

  //If the previous node is NULL, we are deleting the element at the top of the list
  if(previous == NULL){
    list -> top = current -> next;
  }
  //Else remove the current element by delinking from the list
  else {
    previous -> next = current -> next;
  }

  //Free the current node from memory
  free(current);

  list -> size--;
  return list;
}

void printList(LinkedList list){
  int count;

  //Only print the list if there are 1 or more nodes
  if(list->size > 0){

    printf("Contents of list:\n");

    for(count=0; count<list->size; count++){
      printf("Element %d is %d\n", count, getNode(list, count));
    }

    printf("\n");

  } else {
    printf("The list is empty.");
  }
}

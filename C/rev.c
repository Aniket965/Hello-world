#include <stdio.h>
#include <stdbool.h>
 
#define MAXSIZE 7
#define TRUE 1
#define FALSE 0 
 
// defining Stack data structure
    int top=-1;
    int stack[MAXSIZE];

//Initializes the top index to -1


 

//Checks if Stack is Full or not 
bool isFull() {   
    if(top >= MAXSIZE-1)
        return TRUE;
    else
        return FALSE;
}
 

//Checks if Stack is Empty or not
bool isEmpty() {
 if(top == -1)
     return TRUE;
 else
     return FALSE;
}
 

//Adds an element to stack and then increment top index 
void push(int num) {
    if (isFull())
        printf("Stack is Full\n");
    else {
        stack[top + 1] = num;
        top++;
    }
}
 

//Removes top element from stack and decrement top index
int pop() {
    if (isEmpty())
        printf("Stack is Empty...\n");
    else {
     top = top - 1;
        return stack[top+1];
    }
}
 
//Prints elements of stack using recursion
void printStack(){
 if(!isEmpty()){
     int temp = pop();
     printStack();
     printf(" %d ", temp);
     push( temp);
    }
}
void insertAtBottom(int item) {
    if (isEmpty()) {
        push(item);
    } else {
  
        /* Store the top most element of stack in top variable and 
        recursively call insertAtBottom for rest of the stack */
        int temp = pop();
        insertAtBottom(item);
  
        /* Once the item is inserted at the bottom, push the 
        top element back to stack */
        push(temp);
    }
}
 
void reverse() {
    //if stack is not empty
    if (!isEmpty()) {
        /* keep on popping top element of stack in 
        every recursive call till stack is empty  */
        int temp = pop();
        reverse();
  
        /* Now, instead of inserting element back on top 
        of stack, we will insert it at the bottom of stack */
        insertAtBottom(temp);
    }
}

//Returns the number of elements in Stack
int getSize(){
 return top+1;
}
 
int main() {
    /* Adding elements in stack */
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    printf("Original Stack\n");
    printStack();
    reverse();
    printf("\nReversed Stack\n");
    printStack();
    return 0;
}
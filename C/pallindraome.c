#include <stdio.h>
#include <string.h>
 
#define MAXSIZE 100
#define TRUE 1
#define FALSE 0 
char stack[MAXSIZE];
int top = -1;
 

int isFull() {   
    if(top >= MAXSIZE-1)
        return TRUE;
    else
        return FALSE;
}
 
int isEmpty() {
 if(top == -1)
     return TRUE;
 else
     return FALSE;
}
 

void push(int num) {
    if (isFull())
        printf("Stack is Full...\n");
    else {
        stack[top + 1] = num;
        top++;
    }
}
 
int pop() {
    if (isEmpty())
        printf("Stack is Empty...\n");
    else {
     top = top - 1;
        return stack[top+1];
    }
}
 
int main() {
    char inputString[100];
    int i, length;
    printf("Enter a string\n");
    gets(inputString);
    length = strlen(inputString);
    for(i = 0; i < length; i++){
        push(inputString[i]);
    }
    for(i = 0; i < length; i++){
        if(pop() != inputString[i]) {
            printf("Not a Palindrome String\n");
            return 0;
        }
    }
 
    printf("Palindrome String\n");
    return 0;
}
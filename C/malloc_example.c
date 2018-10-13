#include <stdio.h>
#include <stdlib.h>

int main()
{
 int *ptr;    // declare a pointer to an integer
 ptr = (int *) malloc(sizeof(int));  // allocate dynamic memory in the heap

 if (ptr == NULL)     // check to see that the memory was allocated
 {
   printf("Error!! Insufficient memory!!! \n");
   exit(1);
 }

 printf("Enter an integer: ");
 scanf("%d", ptr);         // set the variable pointed to by ptr

 printf("\nYour number was : %d\n", *ptr);

 free(ptr);  // free up the memory you allocated
}


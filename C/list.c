#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node 
{
   int data;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

//display the list
void display() 
{
   struct node *ptr = head;
 
	
   //start from the beginning
   while(ptr != NULL) 
   {
      printf("%d  ",ptr->data);
      ptr = ptr->next;
   }
	
   
}
/* adds a new node at the end of the linked list */
void insertAtEnd(int num)
{
    struct node *ptr,  *temp = head;

    /*create a new node */
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = num;
    ptr->next = NULL;

    /* if the linked list is empty */
    if (head == NULL)
    {
        head = ptr;
    } 
    else
    {
        /* traverse the linked list till the last node is reached */
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = ptr;
    }
    printf("%d is inserted at the end\n",num );
}

/* insert at the specified node in the doubly linked list */
void insertAfter(int num,int key)
{
    struct node *ptr,  *temp = head;

    /*create a new node */
    ptr =(struct node *) malloc(sizeof(struct node));
    ptr->data = num;
    ptr->next = NULL;

    /* if the linked list is empty */
    if (head == NULL)
    {
        printf("\nkey not found");
    } 
    else
    {
        /* traverse the linked list till the last node is reached */
        while (temp->data != key )
        {
        	if(temp->next!=NULL)
	            temp = temp->next;
	        else
	        {
	        	printf("\nkey not found");
	        	return;
	        }
        }
        

        if(temp->next==NULL)
        {
        	temp->next=ptr;
        }
        else
        {
        	ptr->next=temp->next;
        	temp->next=ptr;
        }
        printf("%d inserted after %d\n",num,key );
    }
}

//insert link at the first location
void insertAtStart(int data) 
{
   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
	
   link->data = data;
	
   //point it to old first node
   link->next = head;
	
   //point first to new first node
   head = link;
   printf("%d is insert at start\n",data );
}

//delete first item
void deleteFirst() 
{

   //save reference to first link
   struct node *tempLink = head;
	
   //mark next to first link as first 
   head = head->next;

   //return the deleted link
   free(tempLink);
   printf("First element is deleted\n");
}

//is list empty
bool isEmpty() 
{
  if(head == NULL)
  	return 1;
  return 0;
}

int length() 
{
   int length = 0;
   struct node *current;
	
   for(current = head; current != NULL; current = current->next) 
   {
      length++;
   }
	
   return length;
}

//find a link with given key
bool search(int key) 
{

   //start from the first link
   struct node* current = head;

   //if list is empty
   if(head == NULL) 
   {
      return 0;
   }

   //navigate through list
   while(current->data != key) 
   {
	
      //if it is last node
      if(current->next == NULL) 
      {
         return 0;
      } 
      else 
      {
         //go to next link
         current = current->next;
      }
   }      
	
   //if data found, return the current Link
   return 1;
}

//delete a link with given key
void delete(int key) 
{

   //start from the first link
   struct node* current = head;
   struct node* previous = NULL;
	
   //if list is empty
   if(head == NULL) 
   {
      return;
   }

   //navigate through list
   while(current->data != key) 
   {

      //if it is last node
      if(current->next == NULL) 
      {
         return;
      } 
      else 
      {
         //store reference to current link
         previous = current;
         //move to next link
         current = current->next;
      }
   }

   //found a match, update the link
   if(current == head) 
   {
      //change first to point to next link
      head = head->next;
   } 
   else 
   {
      //bypass the current link
      previous->next = current->next;
   }    
	
   free(current);
   printf("%d deleted successfully\n",key );
}

void sort() 
{

   int i, j, k, tempData;
   struct node *current;
   struct node *next;
	
   int size = length();
   k = size ;
	
   for ( i = 0 ; i < size - 1 ; i++ ) {
      current = head;
      next = head->next;
		
      for ( j = 1 ; j < k ; j++ ) {   

         if ( current->data > next->data ) 
         {
            tempData = current->data;
            current->data = next->data;
            next->data = tempData;
         }
			
         current = current->next;
         next = next->next;
      }
      k--;
   }   
    
   printf("sorted successfully\n");  
}



int main() 
{
  int n, ch,key;
    do
    {
        printf("\n\nOperations on linked list");
        printf("\n1. Insert at end \n2. Add at beginning \n3. Insert after key\n4. Delete first Item\n5. Delete Item\n6. Sort List\n7. Search\n8. Display\n0. Exit\n");
        printf("\nEnter Choice 0-8? : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                printf("\nEnter number: ");
                scanf("%d", &n);
                insertAtEnd(n);
                break;
            case 2:
                printf("\nEnter number: ");
                scanf("%d", &n);
                insertAtStart(n);
                break;
            case 3:
            	printf("\nEnter number: ");
                scanf("%d", &n);
                printf("Enter key: ");
                scanf("%d",&key);
                insertAfter(n,key);
                break;
            case 4:
                deleteFirst();
                break;
            case 5:
            	printf("\nEnter number: ");
                scanf("%d", &n);
                delete(n);
                break;
            case 6:
                sort();
                break; 
            case 7:
            	printf("\nEnter number: ");
                scanf("%d", &n);
            	if(search(n)==1)
            		printf("Found\n");
            	else
            		printf("Not Found\n");
            	break; 
            case 8:
                display();
                break;	         
        }
    }while (ch != 0);

   return 0;
}
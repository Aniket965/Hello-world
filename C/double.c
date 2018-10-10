#include <stdio.h>
#include <stdlib.h>

/* structure representing a node of the doubly linked list */
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *start = NULL;

void insertAtEnd(int);
void insertAtStart(int);
void insertAfter(int,int);
void display();

int main()
{
    int n, ch,key;
    do
    {
        printf("\n\nOperations on doubly linked list");
        printf("\n1. Insert at end \n2. Add at beginning \n3. Insert after key\n4. Display\n0. Exit\n");
        printf("\nEnter Choice 0-4? : ");
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
                display();
                break;
        }
    }while (ch != 0);

    
    return 0;
}

/* adds a new node at the end of the doubly linked list */
void insertAtEnd(int num)
{
    struct node *ptr,  *temp = start;

    /*create a new node */
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = num;
    ptr->next = NULL;
    ptr->prev = NULL;

    /* if the linked list is empty */
    if (start == NULL)
    {
        start = ptr;
    } 
    else
    {
        /* traverse the linked list till the last node is reached */
        while (temp->next != NULL)
            temp = temp->next;

        ptr->prev = temp;
        temp->next = ptr;
    }
}

/* adds a new node at the begining of the linked list */
void insertAtStart(int num)
{
    struct node *ptr;

    /* create a new node */
    ptr = (struct node *)malloc(sizeof(struct node));

    /* assign data and pointer to the new node */
    ptr->prev = NULL;
    ptr->data = num;
    ptr->next = start;

    if (start != NULL)
        start->prev = ptr;
    start = ptr;
}


/* insert at the specified node in the doubly linked list */
void insertAfter(int num,int key)
{
    struct node *ptr,  *temp = start;

    /*create a new node */
    ptr =(struct node *) malloc(sizeof(struct node));
    ptr->data = num;
    ptr->next = NULL;
    ptr->prev = NULL;

    /* if the linked list is empty */
    if (start == NULL)
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
        	ptr->prev=temp;
        }
        else
        {
        	ptr->next=temp->next;
        	ptr->prev=temp;
        	temp->next->prev=ptr;
        	temp->next=ptr;
        }
        printf("%d inserted\n",num );
    }
}

/* displays the contents of the linked list */
void display()
{
	struct node *temp = start;
    printf("\n");

    /* traverse the entire linked list */
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    } 
}
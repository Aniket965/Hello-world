#include<stdio.h>
#include<malloc.h>

struct node
{
 int info;
 struct node *next;
 struct node *prev;
} *first = NULL, *temp, *t;

void insertl()
{
    struct node* ptr = (struct node*) malloc(sizeof(struct node));
    int value;
    printf("Enter the value to be inserted: ");
    scanf("%d", &value);
    ptr -> info = value;
    if(first == NULL)
    {
        first = ptr;
        ptr -> next = NULL;
        ptr -> prev = NULL;
    }
    else
    {
        temp = first;
        while(temp -> next != NULL)
            temp = temp -> next;
        temp -> next = ptr;
        ptr -> prev = temp;
        ptr -> next = NULL;
    }
}
void display()
{
    if(first == NULL)
        printf("List Is Empty.\n");
    else
    {
        temp = first;
        while(temp != NULL)
        {
            printf("%d ", temp -> info);
            temp = temp -> next;
        }
        printf("\n");
    }
}
void deletel()
{
    if(first == NULL)
        printf("List is already empty.\n");
    else
    {
        t = first;
        temp = first;
        while(temp -> next != NULL)
        {
            t = temp;
            temp = temp -> next;
        }
        if(temp == first)
            first = NULL;
        else
            t -> next = NULL;
        printf("Element deleted: %d\n", temp -> info);
        free(temp);
    }
}

int main()
{
    int ch;
    while(1)
    {
        printf("DOUBLY LINKED LIST.");
        printf("\n1.Insert at last.\n2.Delete from last.\n3.Display.\nPress any other key to exit.\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1 : insertl();
                     break;
            case 2 : deletel();
                     break;
            case 3 : display();
                     break;
            default : exit(0);
        }
    }
    return 0;
}

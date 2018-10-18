// [switch case to create, insert, delete, count and display a linked list]

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head;



void append(int num)
{
    struct node *temp,*right;
    temp= (struct node *)malloc(sizeof(struct node));
    temp->data=num;
    right=(struct node *)head;
    while(right->next != NULL)
        right=right->next;
    right->next =temp;
    right=temp;
    right->next=NULL;
}



void add( int num )
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=num;
    if (head== NULL)
    {
        head=temp;
        head->next=NULL;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
}
void addafter(int num, int loc)
{
    int i;
    struct node *temp,*left,*right;
    right=head;
    for(i=1;i<loc;i++)
    {
        left=right;
        right=right->next;
    }
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=num;
    left->next=temp;
    left=temp;
    left->next=right;
    return;
}



void insert(int num)
{
    int c=0;
    struct node *temp;
    temp=head;
    if(temp==NULL)
    {
        add(num);
    }
    else
    {
        while(temp!=NULL)
        {
            if(temp->data<num)
                c++;
            temp=temp->next;
        }
        if(c==0)
            add(num);
        else if(c<count())
            addafter(num,++c);
        else
            append(num);
    }
}



int delete(int num)
{
    struct node *temp, *prev;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data==num)
        {
            if(temp==head)
            {
                head=temp->next;
                free(temp);
                return 1;
            }
            else
            {
                prev->next=temp->next;
                free(temp);
                return 1;
            }
        }
        else
        {
            prev=temp;
            temp= temp->next;
        }
    }
    return 0;
}


void  display(struct node *r)
{
    r=head;
    if(r==NULL)
    {
        return;
    }
    while(r!=NULL)
    {
        printf("%d ",r->data);
        r=r->next;
    }
    printf("\n");
}


int count()
{
    struct node *n;
    int c=0;
    n=head;
    while(n!=NULL)
    {
        n=n->next;
        c++;
    }
    return c;
}


int  main()
{
    int i,num;
    struct node *n;
    head=NULL;
    while(1)
    {
        printf("\nList Operations\n");
        printf("1.Insert\n");
        printf("2.Display\n");
        printf("3.Size\n");
        printf("4.Delete\n");
        printf("5.Exit\n");
        printf("Enter your choice : ");
        if(scanf("%d",&i)<=0){
            printf("Enter only an Integer\n");
            exit(0);
        } else {
            switch(i)
            {
                case 1:      printf("Enter the number to insert : ");
                    scanf("%d",&num);
                    insert(num);
                    break;
                case 2:     if(head==NULL)
                    {
                        printf("List is Empty\n");
                    }
                    else
                    {
                        printf("Element(s) in the list are : ");
                    }
                    display(n);
                    break;
                case 3:     printf("Size of the list is %d\n",count());
                    break;
                case 4:     if(head==NULL)
                        printf("List is Empty\n");
                    else{
                        printf("Enter the number to delete : ");
                        scanf("%d",&num);
                        if(delete(num))
                            printf("%d deleted successfully\n",num);
                        else
                            printf("%d not found in the list\n",num);
                    }
                    break;
                case 5:     return 0;
                default:    printf("Invalid option\n");
            }
        }
    }
    return 0;
}
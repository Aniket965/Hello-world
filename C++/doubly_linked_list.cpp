/* 

The program implements a doubly linked list using classes in c++.
The following four functions have been implemented:-

1.insert_head - for inserting the nodes at the beginning of the list

2.insert_tail - for inserting the nodes at the end of the list

3.display - for showing the list in the forward direction

4.rev_display - for displaying the list in the reverse direction

Wiki - https://en.wikipedia.org/wiki/Doubly_linked_list
*/ 
#include <iostream>

using namespace std;

class node
{
    int data;
    node *next;
    node *prev;
public:
    void insert_head(int data);
    void insert_tail(int data);
    void display();
    void rev_display();

};

node *head;

void node :: insert_head(int data)
{
    node *temp;
    temp = new node;
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL)
    {
        head = temp;
        return;
    }
    head->prev = temp;
    temp->next = head;
    head = temp;
    return;
}

void node ::  insert_tail(int data)
{
    node *temp;
    temp = new node;
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;

    if(head == NULL)
    {
        head = temp;
        return;
    }
    
    node *temp1;
    temp1 = head;
    while(temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = temp;
    temp->prev = temp1;
    return;
}

void node ::  display()
{
    node *temp;
    temp = head;
    while(temp != NULL)
    {
        cout<<"\nThe data inserted is: "<<temp->data;
        temp = temp->next;
    }
    return;
}

void node :: rev_display()
{
    node *temp;
    temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    while(temp != NULL)
    {
        cout<<"\nThe data inserted is: "<<temp->data;
        temp = temp->prev;
    }
    return;
}

int main()
{
    head = NULL;
    int flag = 1,i,data,n;
    node abc;
    while(flag == 1)
    {
        cout<<"\n1.Enter at the end of the linked list";
        cout<<"\n2.Enter at the beginning of the linked list";
        cout<<"\n3.Print the linked list";
        cout<<"\n4.Print Reverse of the list"; 
        cout<<"\nEnter your choice: ";
        cin>>i;
        switch(i)
        {
            case 1: cout<<"\nEnter the value to be inserted in list: ";
                    cin>>data;
                    abc.insert_tail(data);
                    break;
            case 2: cout<<"\nEnter the value to be inserted in list: ";
                    cin>>data;
                    abc.insert_head(data);
                    break;
            case 3: abc.display();
                    break;
            case 4: abc.rev_display();
                    break;
        }
        cout<<"\nDo you want to continue(1-yes/0-no): ";
        cin>>flag;
    }
    return 0;
}
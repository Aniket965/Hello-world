/* 

The program reverses a linked list using recursion.

Wiki - https://en.wikipedia.org/wiki/Linked_list
     - https://en.wikipedia.org/wiki/Recursion_(computer_science)
*/ 
#include <iostream>

using namespace std;

class node
{
    int data;
    node *next;
public:
    void insert(int data);
    void display();
    void rev_list(node *);

};

node *head;

void node :: insert(int data)
{
    node *temp;
    temp = new node ;
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;    
    }
    else
    {
        node *temp2;
        temp2 = head;
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp;
    }
}
void node :: display()
{
    node *temp;
    temp = head;
    while (temp != NULL)
    {
         wcout<<"The data is: "<<temp->data;
        cout<<endl;
        temp = temp->next;
        //cout<<"temp->next is: "<<temp<<endl;

    }
}

void node :: rev_list(node *temp)
{
    if(temp->next == NULL)
    {
        head = temp;
        return;
    }
    rev_list(temp->next);
    temp->next->next = temp;
    temp->next = NULL;
}

int main()
{
    head = NULL;
    int flag = 1,i,data,n;
    node abc;
    while(flag == 1)
    {
        cout<<"\n1.Enter at the end of the linked list";
        cout<<"\n2.Print the linked list";
        cout<<"\n3.Reverse the list recursively";
        cout<<"\nEnter your choice: ";
        cin>>i;
        switch(i)
        {
            case 1: cout<<"\nEnter the value to be inserted in list: ";
                    cin>>data;
                    abc.insert(data);
                    break;
            case 2: abc.display();
                    break;
            case 3: abc.rev_list(head);
                    break;
        }
        cout<<"\nDo you want to continue(1-yes/0-no): ";
        cin>>flag;
    }
    return 0;
}
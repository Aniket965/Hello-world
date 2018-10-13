#include <iostream>
using namespace std;

class node
{
private:
    int data;
    node* next;
    node*prev;
   public:
    node(int d)
    {
        data=d;
        next=NULL;
        prev=NULL;
    }
   friend class LinkedList;
};

class LinkedList
{
public:
    node* head,*tail;
    LinkedList()
    {
        head=NULL;
        tail=NULL;
    }
    
    void insertAtFront(int data)
    {
        if(head==NULL)
            head=tail=new node(data);
            else
            {
                node*n=new node(data);
                head->prev=n;
                n->next=head;
                n->prev=NULL;
                head=n;
            }
    }
    
    int getlength()
    {
        int l=0;
        node *temp=head;
        while(temp)
        {
            l++;
            temp=temp->next;
        }
        return l;
    }
    
    void insertAtMiddle(int d,int p)
    {
        if(p==0)
            insertAtFront(d);
        if(p>getlength())
            insertAtTail(d);
        else
        {
            int jumps=1;
            node *temp=head;
            while(jumps<=p-1)
            {
                temp=temp->next;
                jumps++;
            }
            node*n=new node(d);
            n->prev=tail;
            n->next=temp;
            temp->next=n;
        }
    }
    

    
    void insertAtTail(int data)
    {
        if(head==NULL)
            head=tail=new node(data);
        else
        {
            node *n=new node(data);
            
            n->prev=tail;
            tail->next=n;
            tail=n;
            
        }
    }
    
    
    void print()
    {
        node*temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" --> ";
            temp=temp->next;
        }
        cout<<endl;
    }
    void printrev()
    {
        node*temp=tail;
        while(temp!=NULL)
        {
            cout<<temp->data<<" --> ";
            temp=temp->prev;
        }
        cout<<endl;
    }
  
    void printReverse(node *temp)
    {
        if(temp==NULL)
        {
            return;
        }
        printReverse(temp->next);
        cout<<temp->data<<" --> ";
    }
    
};

int main()
{
    LinkedList l;
    l.insertAtFront(4);
    l.insertAtFront(3);
    l.insertAtFront(2);
    l.insertAtFront(6);
    l.insertAtTail(5);
    l.insertAtTail(7);
    l.insertAtTail(9);
    l.printReverse(l.head);
    l.print();
    l.printrev();
    
    return 0;
}

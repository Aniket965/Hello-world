#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
    
};

class queue
{
public:
    node* front;
    node*rear;
    
    queue() {
        front=rear=NULL;
    }
    
    void push(int x) {
        node *p=new node;
        p->data=x;
        p->next=NULL;
        if(front==NULL)
        {
            front=rear=p;
            rear->next=NULL;
        }
        else
        {
            rear->next=p;
            rear=p;
            rear->next=NULL;
        }
    }
    
    int pop() {
        int x=0;
        if(front==NULL)
        {
            cout<<"Queue Underflow";
            return 0;
        }
        if(front->data!=1){
            x=front->data;
        }
        front=front->next;
        return x;
    }
    
    
    
};


int main() {
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<"Element is "<<q.pop()<<endl;
    cout<<"Element is "<<q.pop()<<endl;
    cout<<"Element is "<<q.pop()<<endl;
    cout<<"Element is "<<q.pop()<<endl;
}

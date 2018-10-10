#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

class stack
{
public:
    node* top;
    stack() {
        top=NULL;
    }
    
    void push(int x) {
        node* ptr=new node;
        ptr->data=x;
        ptr->next=NULL;
        if(top!=NULL)
        ptr->next=top;
        top=ptr;
    }
    
    int pop() {
        node* temp;
        if(top==NULL) {
            cout<<"Stack Underflow";
            return 0;
        }
        temp=top;
        top=top->next;
        return temp->data;
    }
    
    void show() {
        while (top!=NULL) {
            cout<<top->data<<">>";
            top=top->next;
        }
    }
    
};


int main() {
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
   s.show();
  //  cout<< "Element is "<<s.pop()<<endl;
    //cout<< "Element is "<<s.pop()<<endl;
}


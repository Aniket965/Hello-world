#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
void node_ins(node **head,int val)
{
    node *temp = new node();
    temp->data=val;
    temp->next=NULL;
    if((*head) == NULL)
    {
        (*head) = temp;
        return;
    }
    temp->next=(*head);
    (*head)=temp;
}
void display(node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<"\n";
}
int len_iter(node* head)
{
    int count = 0;
    while(head!=NULL)
    {
        count++;
        head=head->next;
    }
    return count;
}
int len_rec(node *head)
{
    if(head==NULL)
        return 0;
    return 1 + len_rec(head->next);
}
int main()
{
    node *head = NULL;
    node_ins(&head,5);
    node_ins(&head,4);
    node_ins(&head,3);
    node_ins(&head,2);
    node_ins(&head,1);
    display(head);
    cout<<"iter :"<<len_iter(head)<<"\n";
    cout<<"rec :"<<len_rec(head)<<'\n';
}

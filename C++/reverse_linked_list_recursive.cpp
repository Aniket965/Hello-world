#include<bits/stdc++.h>
using namespace std;
typedef struct node NODE;
struct node 
{
	int data;
	struct node * next;
};
NODE * insert(NODE * head,int data)
{
	NODE * new_node =  new NODE();
	new_node->data = data;
	new_node->next = NULL;
	if(head==NULL)
	{
		head = new_node;
		return head;
	}
	NODE * temp = head;
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}
	temp->next = new_node;
	return head;
}


void print(NODE * head)
{
	NODE  * temp  = head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}
NODE * head;
void reverse(NODE * temp)
{
	if(temp->next==NULL)
	{
		head = temp;
		return;
	}
	reverse(temp->next);
	NODE * q = temp->next;
	q->next = temp;
	temp->next = NULL;
}



int main()
{
head = NULL;
head = insert(head,2);
head = insert(head,3);
head = insert(head,10);
head = insert(head ,20);
print(head);
cout<<"\n";
reverse(head);
print(head);
}
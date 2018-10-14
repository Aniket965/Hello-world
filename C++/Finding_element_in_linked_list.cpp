#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
};

void Print(struct Node *n,int search)
{	
	while (n!=NULL)
	{
		n->data;
	
		if (n->data==search)
		cout<<"Find \n";
		else
		cout<<"Not Find \n";
		n = n->next;
	 } 
	
}

int main()
{
	
	int search = 2;
	
	struct Node* head =NULL;
	struct Node* second =NULL;
	struct Node* third =NULL;
	
	head = (struct Node*)malloc (sizeof(struct Node));
	second = (struct Node*)malloc (sizeof(struct Node));
	third = (struct Node*)malloc (sizeof(struct Node));
	
	
  head->data = 1;
  head->next = second;

  second->data = 2;
  second->next = third;

  third->data = 3;
  third->next = NULL;
                
  Print(head,search);
	
  return 0;
}

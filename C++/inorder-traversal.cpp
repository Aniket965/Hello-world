#include <iostream>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
	
};

node* newNode(int data)
{
	node* newnode  = new node;

	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;

	return(newnode);
}

//     sample inorder tree
//	   	    25        
//		  /    \
//		 15      35
//		/ \     / 
//	       10  20  30

void inorder(node* root)
{
	if(root)
	{
		inorder(root->left);
		printf("%d\n",root->data );
		inorder(root->right);
	}
}

node* inorderRoot()
{
	node* root = newNode(25);
	root->left = newNode(15);
	root->right = newNode(35);
	root->left->left = newNode(10);
	root->left->right = newNode(20);
	root->right->left = newNode(30);
	return root;
}

int main()
{
	inorder(inorderRoot()); 
	cout<<"########"<<'\n';
	return 0;
}

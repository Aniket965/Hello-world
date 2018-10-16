/*
This AVL tree is implemeted by iamnotabear.
I give you full permission to use it as you want.
*/

#include<bits/stdc++.h>

using namespace std;

struct node{			//structure of the node for the tree.
	int key;
	int height;
	struct node* right;
	struct node* left;
	struct node* parent;
};
typedef struct node block;	//alias


int max(int a,int b){		//for finding max between two numbers.
	if(a>b){return a;}
	else{return b;}
}



int height(block* x){		//for finding height of the node && also two handle the case of NULL pointers of leaves	
	if(x==NULL){		//this function returns the value of NULL as -1.
		return -1;
	}
	else{
		return x->height;
	}
}



void updateHeight(block* x){					// to update the height of a single node.
	x->height=max(height(x->left),height(x->right))+1;
}		

void fullupdateHeight(block*x){ 		//for updating height of the whole tree i.e. upto ROOT NODE.
	if(x==NULL){return;}
	else{
		updateHeight(x);
	}
	x=x->parent;
	fullupdateHeight(x);
}



void leftRotate(block* x,block** root){ 		//left rotating a node x.

	block * y=(block*)malloc(sizeof(block));	//dynamically allocating a node type pointer.
	y=x->right;					//pointing the newly made y pointer to x's right child.

	y->parent=x->parent;				//making x's parent node parent of y.

	if(y->parent!=NULL){				//if the parent exists then.
		if(y->parent->left==x )			//if x was left child .
		{
			y->parent->left=y;		//make y the left child of x's parent.
		}
		else					//else
		{
			y->parent->right=y;		//make y the right child of x's parent.
		}
	}
	else{
		*root=y;				//if the parent do not exist i.e. root node make y the root.
	}

	x->right=y->left;	//making y's left child, x's right child (because y can't point to three node and to maintain inorder).
	if(x->right!=NULL){		//if the left child of y was not NULL
		x->right->parent=x;	//make x the parent of it.
	}
	y->left=x;			//make y's left pointer to point to the x.
	x->parent=y;			//make y   x's parent. 
	fullupdateHeight(x);		//update height of x(because rotation change heights).
	fullupdateHeight(y);		//update height of y(because rotation change heights).
}


void rightRotate(block* x,block** root){		//same as left rotate(just reverse left and right).
	block * y=(block*)malloc(sizeof(block));
	y=x->left;

	y->parent=x->parent;

	if(y->parent!=NULL){
		if(y->parent->right==x )
		{
			y->parent->right=y;
		}
		else
		{
			y->parent->left=y;
		}
	}
	else{
		*root=y;
	}

	x->left=y->right;
	if(x->left!=NULL){
		x->left->parent=x;
	}
	y->right=x;
	x->parent=y;
	fullupdateHeight(x);
	fullupdateHeight(y);
}


void balance(block* y,block** root){		//usnig leftRotate() and rightRotate() to balance the tree.

	if(y==NULL){return;}
	else{
		if(height(y->left)>=height(y->right)+2){		     //left heavy
			if(height(y->left->left)>height(y->left->right)){	//zig-zig type
				rightRotate(y,root);
			}
			else{
				leftRotate(y->left,root);			//zig-zag type
				rightRotate(y,root);
			}
		}
		else if(height(y->right)>=2+height(y->left)){			//right heavy
			if(height(y->right->right)>=height(y->right->left)){	//zig-zig type
				leftRotate(y,root);
			}
			else{							//zig-zag type
				rightRotate(y->right,root);
				leftRotate(y,root);
			}
		}

		y=y->parent;
		balance(y,root);						//recursion till ROOT NODE.
	}
}


void insert(block** root,int data){   				//insert same as BST.
	block* node=(block*)malloc(sizeof(block));
	node->key=data;
	node->right=NULL;
	node->left=NULL;
	node->height=0;
	block* y=NULL;

	block* x=*root;

	while((x)!=NULL){
		y=x;

		if((node)->key<x->key){ 
			x=x->left; 
		}
		else{x=x->right;}
	}

	(node)->parent=y; 
	if(y==NULL){
		*root=(node);
	}
	else if((node)->key < y->key){
		y->left=(node);
		fullupdateHeight(y);
		balance(y,root);
	}
	else{
		y->right=(node);
		fullupdateHeight(y);
		balance(y,root);
	}
}


void preorder(block* root){			//preorder traversal.
	if(root==NULL){
		return;
	}
	cout <<"root->key"<<" "<<root->key <<" "<<"root->height"<<" "<<root->height<<'\n';
	preorder(root->left);
	preorder(root->right);
}



int main(){

	block* root=NULL;
	int n;
	cin >> n;

	int data;
	for(;n>0;n--){
		cin >> data;
		insert(&root,data);
	}

	preorder(root);

}

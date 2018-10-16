#include<bits/stdc++.h>
using namespace std;
 
struct Node
{
    struct Node *left, *right;
    int info;
 

    bool lthread;
 

    bool rthread;
};

struct Node *insert(struct Node *root, int ikey)
{

    Node *ptr = root;
    Node *par = NULL; 
    while (ptr != NULL)
    {

        if (ikey == (ptr->info))
        {
            printf("Duplicate Key !\n");
            return root;
        }
 
        par = ptr; 
 

        if (ikey < ptr->info)
        {
            if (ptr -> lthread == false)
                ptr = ptr -> left;
            else
                break;
        }
 
        else
        {
            if (ptr->rthread == false)
                ptr = ptr -> right;
            else
                break;
        }
    }
 
    Node *tmp = new Node;
    tmp -> info = ikey;
    tmp -> lthread = true;
    tmp -> rthread = true;
 
    if (par == NULL)
    {
        root = tmp;
        tmp -> left = NULL;
        tmp -> right = NULL;
    }
    else if (ikey < (par -> info))
    {
        tmp -> left = par -> left;
        tmp -> right = par;
        par -> lthread = false;
        par -> left = tmp;
    }
    else
    {
        tmp -> left = par;
        tmp -> right = par -> right;
        par -> rthread = false;
        par -> right = tmp;
    }
 
    return root;
}
 
struct Node *inorderSuccessor(struct Node *ptr)
{
    if (ptr -> rthread == true)
        return ptr->right;
 
    ptr = ptr -> right;
    while (ptr -> lthread == false)
        ptr = ptr -> left;
    return ptr;
}
 
void inorder(struct Node *root)
{
    if (root == NULL)
        printf("Tree is empty");
    struct Node *ptr = root;
    while (ptr -> lthread == false)
        ptr = ptr -> left;

    while (ptr != NULL)
    {
        printf("%d ",ptr -> info);
        ptr = inorderSuccessor(ptr);
    }
}

void preorder(struct Node *root){

   if (root == NULL)
        printf("Tree is empty");
    struct Node *ptr = root;
	
	printf("%d ",ptr -> info);
	if(ptr->lthread==false)
		preorder(ptr->left);
	if(ptr->rthread==false)
		preorder(ptr->right);

}
 
int main()
{
	int n, arr[100];
	struct Node *root = NULL;
    cout<<"Enter no of nodes of tree.\n";
    cin>>n;
    cout<<"Enter "<<n<<" numbers.\n";
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
        root = insert(root, arr[i]);
    }
    
 
    inorder(root);
    cout<<endl;
    preorder(root);
 
    return 0;
}

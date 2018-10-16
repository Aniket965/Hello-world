#include <iostream>
#define type int
using namespace std;
 int test=1;
class node

{//begin node class
private:

public:
type data;
    node *left;
    node *right;
    int height;
    friend class AVL;

};//end of node class

class AVL
{//begin AVL
private:


public:
  node* rotate_right(node* n);
    node* rotate_left(node* n);
node *root=NULL;
node* get_root();//def
node* ins(node* n,type x);//def
node* del(node* n,type x);
node* LL(node *n);
node* RR(node *n);
node* LR(node *n);
node* RL(node *n);
node* balance(node *temp);
void preorder(node *n);
void inorder(node *n);
int get_height(node* n);
int Balance_factor(node* n);//def
};//end AVL
//begin AVL functions
void AVL::preorder(node *n)
{
if(n!=NULL)
{
cout<<" "<<n->data;
preorder(n->left);
preorder(n->right);
}

}
node* AVL::balance(node* temp)
{
    int bal_factor = Balance_factor(temp);
    if (bal_factor > 1)
    {
        if (Balance_factor(temp->left) > 0)
            temp = LL(temp);
        else
            temp = LR(temp);
    }
    else if (bal_factor < -1)
    {
        if (Balance_factor(temp->right) > 0)
            temp = RL(temp);
        else
            temp = RR(temp);
    }
    return temp;
}





node* AVL::get_root()
{//begin get root
return root;
}//end get_root
node* AVL::ins(node* n,type x)
{//begin ins
//cout<<"here in ins"<<endl;

    if(n==NULL)
    {

    node* y=new node();
    y->data=x;
    y->left=NULL;
    y->right=NULL;
    n=y;
    if(test==1)cout<<"Root added "<<n->data<<endl;
    test=0;
    return n;

    }
    else{//begin else
        if(x>n->data)
        {//begin if

            n->right=ins(n->right,x);

            cout<<x<<" added to right of "<<n->data<<endl;
            cout<<Balance_factor(n)<<endl;
           n=balance(n);
        }//end if
        else
        {//begin else

            n->left=ins(n->left,x);
            cout<<x<<" added to left of "<<n->data<<endl;
            cout<<Balance_factor(n)<<endl;
            n=balance(n);

        }//end else
    }//end else
return n;
}//end ins
node* AVL::del(node* n,type x)
{//begin del


return n;
}//end del
node* AVL::rotate_right(node* n)
{//begin rotate right
node* temp=new node();
temp=n->left;
n->left=temp->right;
temp->right=n;
n->height=get_height(n);
temp->height=get_height(temp);
return temp;
}//end rotate right
node* AVL::rotate_left(node* n)
{//begin rotate left
node* temp=new node();
temp=n->right;
n->right=temp->left;
temp->left=n;
n->height=get_height(n);
temp->height=get_height(temp);
cout<<"Rotating left\n";
return temp;

}//end rotate left
int AVL::Balance_factor(node* n)
{//begin balance factor
int l_height = get_height(n->left);
    int r_height = get_height (n->right);
    int b_factor= l_height - r_height;
    return b_factor;


}//end balance factor

int AVL::get_height(node* n)
{//begin get_height
int h=0;
    if (n!= NULL)
    {
        int l_height = get_height (n->left);
        int r_height = get_height (n->right);
        int max_height = max (l_height, r_height);
        h = max_height + 1;
    }

    return h;

}//end get_height

node* AVL::LL(node* n)
{//begin LL
n=rotate_right(n);
cout<<"LL DONE\n";
return n;
}//end LL

node* AVL::RR(node* n)
{//begin RR
n=rotate_left(n);
cout<<"RR DONE\n";
return n;
}//end RR

node* AVL::RL(node* n)
{//begin RL
n->right=rotate_right(n->right);
n=rotate_left(n);
cout<<"RL DONE\n";
return n;
}//end RL

node* AVL::LR(node* n)
{//begin LR
n->left=rotate_left(n->left);
n=rotate_right(n);
cout<<"LR DONE\n";
return n;
}//end LR
void AVL::inorder(node* n)
{
if(n!=NULL)
{
inorder(n->left);
cout<<" "<<n->data;
inorder(n->right);


}


}
//end AVL functions

int main()
{//begin main
 AVL tree;
 int choice;
 cout<<"Enter option\n1.create\n2.add\n3.inorder dispaly\n4.preorder display\n0.exit\n";
 cin>>choice;
 type s;
 while(choice!=0)
 {
 switch(choice)

 {
 case 1:cin>>s;
        tree.root=tree.ins(tree.get_root(),s);
        break;
 case 2:cin>>s;
        tree.root=tree.ins(tree.get_root(),s);
        break;
 case 3:tree.inorder(tree.get_root());
        cout<<endl;
        break;
 case 4:tree.preorder(tree.get_root());
        cout<<endl;
        break;
 case 0:return 0;
        break;
}
cout<<"Enter option\n1.create\n2.add\n3.inorder dispaly\n4.preorder dispaly\n0.exit\n";
cin>>choice;
 }
    return 0;
}//end main

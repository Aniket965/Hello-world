#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
};
 
 vector<int> postorderTraversal(TreeNode* root){
    stack<TreeNode*> st;
    TreeNode* prev=NULL;
    vector<int> v;
    do{
        while(root){
            st.push(root);
            root=root->left;
         }
         while(root==NULL && !st.empty()){
            root=st.top();
            if(root->right==NULL || root->right==prev){
                v.push_back(root->val);
                st.pop();
                prev=root;
                root=NULL;
             }
             else
                root=root->right;
           }
        }while(!st.empty());
        return v;
 }
 
 int main(){
    //Assuming root is the root node of the tree whose postorder traversal is done
    vector<int> v;
    v=postorderTraversal(root);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
 }

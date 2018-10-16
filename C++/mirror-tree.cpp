#include <iostream>
#include <queue>

using namespace std;

class BstNode {
  public:
  int data;
  BstNode *left;
  BstNode *right;
  BstNode(int d) {
    data = d;
    left = NULL;
    right = NULL;
  }  
};


class Tree {
  public:
  BstNode *root;
  Tree() {
    root = NULL;
  }
  void insert(int d) {
    BstNode *newNode = new BstNode(d);
    //cout<<newNode->data<<endl;
    if(root == NULL) {
      root = newNode;
      return;
    }

    BstNode *temp = root;
    int flag = 1;
    while(flag) {
      if(d > temp->data) {
        if(temp->right != NULL)
          temp = temp->right;
        else {
          temp->right = newNode;
          flag = 0;
        }
      }
      else if(d < temp->data) {
        if(temp->left != NULL)
          temp = temp->left;
        else {
          temp->left = newNode;
          flag = 0;
        }
      }
      else 
        flag = 0;
    }
  }

  void levelTraversal() {
    cout<<"Level Traversing"<<endl;
    queue<BstNode*> lvl;
    lvl.push(root);
    while(!lvl.empty()) {
      BstNode *temp = lvl.front();
      lvl.pop();
      if(temp->left != NULL)
        lvl.push(temp->left);
      if(temp->right != NULL)
        lvl.push(temp->right);
      cout<<temp->data<<endl;
    }
  }
};

void swap(BstNode *root) {
  BstNode *temp = root->left;
  root->left = root->right;
  root->right = temp;
}

void mirrorTree(BstNode *root) {
  queue<BstNode*> s;
  s.push(root);
  while(!s.empty()) {
    BstNode *temp = s.front();
    s.pop();
    swap(temp);
    if(temp->left != NULL)
      s.push(temp->left);
    if(temp->right != NULL)
      s.push(temp->right);
  }
}

int main() {
  Tree t;
  t.insert(9);
  t.insert(12);
  t.insert(7);
  t.insert(13);
  t.insert(11);
  t.insert(5);
  t.insert(4);

  t.levelTraversal();
  mirrorTree(t.root);
  t.levelTraversal();
  return 0;
}
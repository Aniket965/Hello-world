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
  BstNode *root;
  public:
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

int main() {
  Tree t;
  t.insert(10);
  t.insert(5);
  t.insert(12);
  t.insert(4);
  t.insert(7);
  t.insert(2);
  t.insert(3);
  t.insert(13);
  t.insert(14);
  t.insert(6);
  t.insert(9);
  t.insert(11);
  t.insert(15);
  t.levelTraversal();
  return 0;
}
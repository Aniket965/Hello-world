int height(Node* root) {
        // Write your code here.
        int leftht=0;
        int rightht=0;
        if(root->left!=NULL)
            leftht=1+height(root->left);
        if(root->right!=NULL)
            rightht=1+height(root->right);
        return max(leftht,rightht);
    }

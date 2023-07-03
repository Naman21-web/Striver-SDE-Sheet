bool check(Node* root){
        if(!root->left && !root->right) return true;
        int leftval=0,rightval=0;
        if(root->left) leftval=root->left->data;
        if(root->right) rightval=root->right->data;
        if(leftval+rightval != root->data) return false;
        int leftcheck=true,rightcheck=true;
         if(root->left) leftcheck=check(root->left);
        if(root->right) rightcheck=check(root->right);
        return leftcheck && rightcheck;
    }
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
     // Add your code here
     return check(root);
    }
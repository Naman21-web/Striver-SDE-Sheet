void flattree(Node* root){
        if(root==NULL) return;
        Node* temp=root->right;
        root->right=root->left;
        root->left=NULL;
        flattree(root->right);
        Node* var = root;
        while(var->right!=NULL) var=var->right;
        var->right=temp;
        flattree(var->right);
    }
    void flatten(Node *root)
    {
        //code here
        flattree(root);
    }
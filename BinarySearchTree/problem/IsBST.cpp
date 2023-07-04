bool isBST(Node* root) 
    {
        // Your code here
        if(root!=NULL){
            if(!isBST(root->left)) return 0;
            if(prev!=NULL && root->data<=prev->data) return 0;
            prev=root;
            return isBST(root->right);
        }
        else return 1;
    }
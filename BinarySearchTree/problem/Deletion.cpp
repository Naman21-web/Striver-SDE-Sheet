TreeNode* inOrderPre(TreeNode* root){
        if(root==NULL) return NULL;
        while(root->right) root=root->right;
        return root;
    }
    TreeNode* inOrderPost(TreeNode* root){
        if(root==NULL) return NULL;
        while(root->left) root=root->left;
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(key<root->val) root->left=deleteNode(root->left,key);
        else if(key>root->val) root->right=deleteNode(root->right,key);
        else{
            if(!root->left && !root->right){ delete(root);return NULL;}
            TreeNode* iPre = inOrderPre(root->left);
            if(iPre!=NULL){root->val=iPre->val;
            root->left = deleteNode(root->left,iPre->val);}
            else{
                TreeNode* iPost = inOrderPost(root->right);
                root->val=iPost->val;
                root->right=deleteNode(root->right,iPost->val);
            }
        }
        return root;
    }
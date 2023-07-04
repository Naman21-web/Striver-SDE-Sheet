void find(Node* root,Node*& pre,Node*& suc,int key){
        if(root==NULL) return;
        if(root->key==key){
            if(root->left) {
                pre = root->left;
                while(pre->right) pre=pre->right;
            }
            if(root->right){
                suc=root->right;
                while(suc->left) suc=suc->left;
            }
            return;
        }
        else if(root->key>key){
            suc=root;
            find(root->left,pre,suc,key);
        }
        else{
            pre=root;
            find(root->right,pre,suc,key);
        }
    }
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        pre=NULL,suc=NULL;
        find(root,pre,suc,key);
    }
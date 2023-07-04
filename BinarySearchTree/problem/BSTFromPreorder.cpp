TreeNode* construct(vector<int> &preorder,int &preorderidx,int key,int min,int max,int n){
        if(preorderidx>=n) return NULL;
        TreeNode* root=NULL;
        if(key>min && key<max) {
            root = new TreeNode(key);
            preorderidx++;
            if(preorderidx<n){
                root->left=construct(preorder,preorderidx,preorder[preorderidx],min,key,n);
            }
            if(preorderidx<n){
                root->right = construct(preorder,preorderidx,preorder[preorderidx],key,max,n);
            }
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // sort(preorder.begin(),preorder.end());
        // return balance(preorder,0,preorder.size()-1);
        int n=preorder.size();
        int preorderidx=0;
        return construct(preorder,preorderidx,preorder[0],INT_MIN,INT_MAX,n);
    }
stack<TreeNode*> st,st2;
    void pushAll(TreeNode* root){
        while(root->left){st.push(root->left);root=root->left;}
    }

    void pushAll2(TreeNode* root){
        while(root->right){st2.push(root->right);root=root->right;}
    }

    int next(){
        TreeNode* currnode=st.top();
        st.pop();
        if(currnode->right){
            st.push(currnode->right);
            pushAll(currnode->right);
        }
        return currnode->val;
    }

    int prev(){
        TreeNode* currnode=st2.top();
        st2.pop();
        if(currnode->left){
            st2.push(currnode->left);
            pushAll2(currnode->left);
        }
        return currnode->val;
    }

    bool findTarget(TreeNode* root, int k) {
        st.push(root);
        st2.push(root);
        pushAll(root);
        pushAll2(root);
        int x = prev();
        int y = next();
        while(x!=y){
            int sum = x+y;
            if(sum==k) return true;
            else if(sum>k) x=prev();
            else y=next();
        }
        return false;
    }
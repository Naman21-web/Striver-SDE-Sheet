stack<TreeNode*> st;
    void pushAll(TreeNode* root){
        while(root->left) {st.push(root->left); root=root->left;}
    }
    BSTIterator(TreeNode* root) {
        st.push(root);
        pushAll(root);
    }
    
    int next() {
        TreeNode* curr=st.top();
        st.pop();
        if(curr->right){
            st.push(curr->right);
            pushAll(curr->right);
        }
        return curr->val;
    }
    
    bool hasNext() {
        if(!st.empty()) return true;
        return false;
    }
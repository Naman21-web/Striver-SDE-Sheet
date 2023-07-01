  void inOrdertraverse(Node* root,vector<int> &ans){
        if(root==NULL) return;
        inOrdertraverse(root->left,ans);
        ans.push_back(root->data);
        inOrdertraverse(root->right,ans);
    }
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int> ans;
        inOrdertraverse(root,ans);
        return ans;
    }
int floor(Node* root, int input) {
    // Code here
    int ans=-1;
    while(root!=NULL){
        if(root->data==input) return input;
        else if(root->data>input) root=root->left;
        else ans=root->data,root=root->right;
    }
    return ans;
}
Node* insert(Node* root, int Key) {
    // Your code here
    if(root==NULL){
        return new Node(Key);
    }
    if(Key==root->data) return root;
    if(Key<root->data) root->left= insert(root->left,Key);
    else root->right=insert(root->right,Key);
    return root;
}

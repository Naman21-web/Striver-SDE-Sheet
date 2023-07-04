bool search(Node* root, int x) {
    // Your code here
    // if(root==NULL) return false;
    // if(root->data==x) return true;
    // if(x<root->data) return search(root->left,x);
    // else return search(root->right,x);
    while(root!=NULL){
        if(root->data==x) return true;
        if(x<root->data) root=root->left;
        else root=root->right;
    }
    return false;
}
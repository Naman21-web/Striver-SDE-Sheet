bool symmetric(Node* root1,Node* root2){
        if((!root1 && root2) || (root1 && !root2)) return false;
        if(!root1 && !root2) return true;
        if(root1->data != root2->data) return false;
        return symmetric(root1->left,root2->right) && symmetric(root1->right,root2->left);
    }
    // return true/false denoting whether the tree is Symmetric or not
    bool isSymmetric(struct Node* root)
    {
	    // Code here
	    if(root==NULL) return true;
	    return symmetric(root->left,root->right);
    }
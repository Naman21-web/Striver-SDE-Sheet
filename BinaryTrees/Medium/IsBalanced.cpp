bool check(Node* root,int &height){
        if(root==NULL){
            height=0;
            return true;
        }
        int lh=0,rh=0;
        bool isLeftBal=check(root->left,lh);
        bool isRightBal=check(root->right,rh);
        if(isLeftBal==false || isRightBal==false) return false;
        height=max(lh,rh)+1;
        if(abs(lh-rh)>1) return false;
        return true;
    }
    bool isBalanced(Node *root)
    {
        //  Your Code here
        int height=0;
        return check(root,height);
    }
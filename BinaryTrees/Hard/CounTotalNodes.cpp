int leftheight(Node* root){
        Node* temp=root;
        int cnt=0;
        while(temp!=NULL) temp=temp->left,cnt++;
        return cnt;
    }
    int rightheight(Node* root){
        Node* temp=root;
        int cnt=0;
        while(temp!=NULL) temp=temp->right,cnt++;
        return cnt;
    }
    int countNodes(Node* root) {
        // Write your code here
        int lh = leftheight(root);
        int rh=rightheight(root);
        if(lh==rh) return (1<<lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
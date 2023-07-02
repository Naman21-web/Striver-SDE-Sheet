int calcDiameter(Node* root,int &height){
        if(root==NULL){
            height=0;
            return 0;
        }
        int lh=0,rh=0;
        int leftdia = calcDiameter(root->left,lh);
        int rightdia = calcDiameter(root->right,rh);
        int currdia = lh+rh+1;
        height = max(lh,rh)+1;
        return max(currdia,max(leftdia,rightdia));
    }
    int diameter(Node* root) {
        // Your code here
        int height=0;
        return calcDiameter(root,height);
    }
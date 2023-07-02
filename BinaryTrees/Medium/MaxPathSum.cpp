int maxSum(Node* root,int &currpath){
        if(root==NULL) return INT_MIN;
        int leftpath=0,rightpath=0;
        int leftsum = maxSum(root->left,leftpath);
        int rightsum = maxSum(root->right,rightpath);
        int maxChildSum = max(leftsum,rightsum);
        currpath = max(root->data,root->data+max(leftpath,rightpath));
        int maxSum = root->data+leftpath+rightpath;
        return max(currpath,max(maxSum,max(root->data,maxChildSum)));
    }
    int findMaxSum(Node* root)
    {
        // Your code goes here
        int currpath=0;
        return maxSum(root,currpath);
    }
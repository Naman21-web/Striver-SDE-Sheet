Info largest(Node* root){
        if(root==NULL) return {0,INT_MIN,INT_MAX,0,true};
        if(root->left==NULL && root->right==NULL) return {1,root->data,root->data,1,true};
        Info leftInfo = largest(root->left);
        Info rightInfo = largest(root->right);
        Info curr;
        curr.size = 1+leftInfo.size+rightInfo.size;
        if(leftInfo.isBST && rightInfo.isBST && leftInfo.max<root->data && rightInfo.min>root->data){
            curr.min = min(leftInfo.min,min(rightInfo.min,root->data));
            curr.max = max(rightInfo.max,max(leftInfo.max,root->data));
            curr.ans=curr.size;
            curr.isBST=true;
            return curr;
        }
        curr.ans = max(leftInfo.ans,rightInfo.ans);
        curr.isBST=false;
        return curr;
    }
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	//Your code here
    	Info curr=largest(root);
    	return curr.ans;
    }
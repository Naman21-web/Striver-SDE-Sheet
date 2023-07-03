int ans=0;
    void subtreeNodes(Node* root,int distance){
        if(root==NULL){
            ans=max(ans,distance-1);
            return;
        }
        subtreeNodes(root->left,distance+1);
        subtreeNodes(root->right,distance+1);
    }
    int FindNode(Node* root,int target){
        if(root==NULL) return -1;
        if(root->data==target){
            subtreeNodes(root,0);
            return 1;
        }
        int dl = FindNode(root->left,target);
        if(dl!=-1){
            subtreeNodes(root->right,dl+1);
            return dl+1;
        }
        int dr = FindNode(root->right,target);
        if(dr!=-1){
            subtreeNodes(root->left,dr+1);
            return dr+1;
        }
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        int x = FindNode(root,target);
        return ans;
    }
vector<int> ans;
    void subtreeNodes(Node* root,int k){
        if(root==NULL) return;
        if(k==0){
            ans.push_back(root->data);
            return;
        }
        subtreeNodes(root->left,k-1);
        subtreeNodes(root->right,k-1);
    }
    int nodesAtK(Node* root,int target,int k){
         if(root==NULL) return -1;
         if(root->data==target){
             subtreeNodes(root,k);
             return 0;
         }
         int ld = nodesAtK(root->left,target,k);
         if(ld!=-1){
             if(ld+1==k){
                 ans.push_back(root->data);
                 
             }
             else{
                 subtreeNodes(root->right,k-ld-2);
             }
             return ld+1;
         }
         int rd = nodesAtK(root->right,target,k);
         if(rd!=-1){
             if(rd+1==k){
                 ans.push_back(root->data);
             }
             else{
                 subtreeNodes(root->left,k-rd-2);
             }
             return rd+1;
         }
         return -1;
    }
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        ans.clear();
        int x = nodesAtK(root,target,k);
       sort(ans.begin(),ans.end());
       return ans;
    }
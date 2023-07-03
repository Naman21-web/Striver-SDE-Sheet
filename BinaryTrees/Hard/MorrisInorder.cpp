vector<int> inOrder(Node* root) {
        
        vector<int> ans;
        Node* curr=root;
        while(curr!=NULL){
            if(curr->left==NULL){
                ans.push_back(curr->data);
                curr=curr->right;
            }
            else{
                Node* prev=curr->left;
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    ans.push_back(curr->data);
                    prev->right=NULL;
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
vector <int> preorder(Node* root)
{
    
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
                // ans.push_back(curr->data);
                prev->right=curr;
                ans.push_back(curr->data);
                curr=curr->left;
            }
            else{
                prev->right=NULL;
                curr=curr->right;
            }
        }
    }
    return ans;
}
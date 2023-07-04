int KthSmallestElement(Node *root, int K) {
        // add code here
        // vector<int> inorder;
        int cnt=0;
        Node* curr=root;
        while(curr!=NULL){
            if(!curr->left){
                cnt++;
                if(cnt==K) return curr->data;
                // inorder.push_back(curr->data);
                curr = curr->right;
            }
            else{
                Node* prev=curr->left;
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                }
                if(!prev->right){
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    cnt++;
                    if(cnt==K) return curr->data;
                    // inorder.push_back(curr->data);
                    prev->right=NULL;
                    curr=curr->right;
                }
            }
        }
        return -1;
        // int n=inorder.size();
        // if(K>n) return -1;
        // return inorder[K-1];
    }
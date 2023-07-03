int getMaxWidth(Node* root) {

        // Your code here
        if(root==NULL) return 0;
        int maxWidth=1;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            maxWidth = max(maxWidth,n);
            for(int i=0;i<n;i++){
                Node* currnode=q.front();
                q.pop();
                if(currnode->left) q.push(currnode->left);
                if(currnode->right) q.push(currnode->right);
            }
        }
        return maxWidth;
    }
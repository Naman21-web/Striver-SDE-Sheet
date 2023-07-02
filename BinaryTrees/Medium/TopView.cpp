vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(root==NULL) return ans;
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                Node* currnode=q.front().first;
                int currlevel=q.front().second;
                q.pop();
                if(mp[currlevel]==0){
                    mp[currlevel]=currnode->data;
                }
                if(currnode->left)q.push({currnode->left,currlevel-1});
                if(currnode->right)q.push({currnode->right,currlevel+1});
            }
        }
        for(auto x:mp) ans.push_back(x.second);
        return ans;
    }
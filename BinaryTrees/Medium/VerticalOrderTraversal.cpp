    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        map<int,vector<int>> mp;
        vector<int> ans;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                Node* currnode=q.front().first;
                int currlevel=q.front().second;
                q.pop();
                if(currnode->left) q.push({currnode->left,currlevel-1});
                if(currnode->right) q.push({currnode->right,currlevel+1});
                mp[currlevel].push_back(currnode->data);
            }
        }
        for(auto vec:mp){
            for(int i=0;i<vec.second.size();i++) ans.push_back(vec.second[i]);
        }
        return ans;
    }
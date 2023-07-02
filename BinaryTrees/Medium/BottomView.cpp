vector<int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            Node* currnode = q.front().first;
            int currlevel = q.front().second;
            q.pop();
            mp[currlevel]=currnode->data;
            if(currnode->left) q.push({currnode->left,currlevel-1});
            if(currnode->right) q.push({currnode->right,currlevel+1});
        }
        for(auto x:mp){
            ans.push_back(x.second);
        }
        return ans;  
    }
vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<vector<int>> newadj(V);
        for(int i=0;i<V;i++){
            for(auto nodes:adj[i]){
                newadj[nodes].push_back(i);
            }
        }
        vector<int> indeg(V,0);
        for(int i=0;i<V;i++){
            for(auto it:newadj[i]){
                indeg[it]++;
            }
        }
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indeg[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:newadj[node]){
                indeg[it]--;
                if(indeg[it]==0) q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }

    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);queue<int> q;
        vector<int> indeg(V,0);
        for(int i=0;i<V;i++){
            for(auto node:adj[i]){
                indeg[node]++;
            }
        }
        for(int i=0;i<V;i++){
            if(indeg[i]==0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            ans.push_back(x);
            for(auto node:adj[x]){
                indeg[node]--;
                if(indeg[node]==0) q.push(node);
            }
        }
        if(ans.size()==V) return false;
        return true;
    }
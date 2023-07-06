bool bfs(int i,vector<int> &vis,vector<int> adj[]){
        queue<pair<int,int>> q;
        vis[i]=true;
        q.push({i,-1});
        while(!q.empty()){
            int curr = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto ele:adj[curr]){
                if(ele!=parent && vis[ele]) return true;
                if(!vis[ele]){
                    vis[ele]=1;
                    q.push({ele,curr});
                }
            }
        }
        return false;
    }
    
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        if(V<3) return false;
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                bool res = bfs(i,vis,adj);
                if(res==true) return true;
            }
        }
        return false;
    }
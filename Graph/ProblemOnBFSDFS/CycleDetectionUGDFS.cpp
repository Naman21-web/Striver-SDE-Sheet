   
    bool dfs(int i,vector<int> &vis,vector<int> adj[],int parent){
        for(auto nodes:adj[i]){
            if(!vis[nodes]){
                vis[nodes]=1;
                if(dfs(nodes,vis,adj,i))return true;
            }
            else if(nodes!=parent) return true;
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
                vis[i]=true;
                if(dfs(i,vis,adj,-1)) return true;
            }
        }
        return false;
    }
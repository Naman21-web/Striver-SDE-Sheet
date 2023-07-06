bool dfs(int i,vector<int> adj[],vector<int> &vis,vector<int> &path){
        path[i]=1;
        for(auto node:adj[i]){
            if(!vis[node]){
                vis[node]=1;
                if(dfs(node,adj,vis,path)) return true;
            }
            else if(path[node])return true;
        }
        path[i]=0;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0),path(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                vis[i]=1;
                if(dfs(i,adj,vis,path))return true;
            }
        }
        return false;
    }
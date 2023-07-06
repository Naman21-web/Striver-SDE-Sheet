void bfs(vector<vector<int>> &adj,int k,vector<int> &vis){
        queue<int> q;
        q.push(k);
        while(!q.empty()){
            int i = q.front();
            q.pop();
            for(int j=0;j<adj[i].size();j++){
                if(i!=j && adj[i][j]==1 && !vis[j]){
                    vis[j]=1;
                    q.push(j);
                }
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int cnt=0;
        vector<int> vis(V,0);
        for(int i=0;i<adj.size();i++){
            if(!vis[i]) {vis[i]=1;bfs(adj,i,vis);cnt++;}
        }
        return cnt;
    }
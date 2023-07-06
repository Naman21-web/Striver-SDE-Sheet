vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<vector<int>> adj(N);
        for(int i=0;i<M;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> dist(N,INT_MAX);
        queue<int> q;
        vector<int> vis(N,0);
        q.push(src);
        dist[src]=0;
        vis[src]=1;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(auto node:adj[x]){
                if(dist[x]+1<dist[node]){
                    dist[node]=dist[x]+1;
                }
                if(!vis[node]) {vis[node]=1;q.push(node);}
            }
        }
        for(int i=0;i<N;i++){
            if(dist[i]==INT_MAX) dist[i]=-1;
        }
        return dist;
    }
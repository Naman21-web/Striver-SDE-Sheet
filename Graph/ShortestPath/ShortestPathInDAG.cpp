void dfs(int node,vector<vector<pair<int,int>>>  &adj,vector<int> &vis,stack<int> &st){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it.first]){
                dfs(it.first,adj,vis,st);
            }
        }
        st.push(node);
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<vector<pair<int,int>>> adj(N);
        for(int i=0;i<M;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        vector<int> vis(N,0);
        stack<int> st;
        for(int i=0;i<N;i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        vector<int> dist(N,INT_MAX);
        dist[0]=0;
        while(st.top()!=0) st.pop();
        while(!st.empty()){
            int node=st.top();
            st.pop();
            for(auto it:adj[node]){
                int v=it.first;
                int wt=it.second;
                if(dist[node]+wt<dist[v]){
                    dist[v] = dist[node]+wt;
                }
            }
        }
        for(int i=0;i<N;i++){
            if(dist[i]==INT_MAX) dist[i]=-1;
        }
        return dist;
    }
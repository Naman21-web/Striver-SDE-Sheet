vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        set<pair<int,int>> st;
        vector<int> dist(V,INT_MAX);
        dist[S]=0;
        
        st.insert({0,S});
        while(!st.empty()){
            auto x = *st.begin();
            st.erase(x);
            for(auto node:adj[x.second]){
                if(dist[node[0]]>dist[x.second]+node[1]){
                    st.erase({dist[node[0]],node[0]});
                    dist[node[0]]=dist[x.second]+node[1];
                    st.insert({dist[node[0]],node[0]});
                }
            }
        }
        for(int i=0;i<V;i++){
            if(dist[i]==INT_MAX) dist[i]=-1;
        }
        return dist;
        
    }
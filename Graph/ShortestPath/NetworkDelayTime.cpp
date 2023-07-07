int minimumCost(vector<vector<int>>& flights, int n, int k) {
        // code here
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
            // cout<<flights[i][0];
        }
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        set<pair<int,int>> st;
        st.insert({0,k});
        while(!st.empty()){
            auto node = *st.begin();
            // cout<<node.
            st.erase(node);
            for(auto it:adj[node.second]){
                if(dist[it.first]>dist[node.second]+it.second){
                    // cout<<dist[it.first]<<" "<<dist[node.second]+it.second<<" ";
                    st.erase({dist[it.first],it.first});
                    dist[it.first]=dist[node.second]+it.second;
                    st.insert({dist[it.first],it.first});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans = max(ans,dist[i]);
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
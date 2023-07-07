int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        int mod=1e9+7;
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<roads.size();i++){
            if(roads[i][0]==roads[i][1]) continue;
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        vector<int> dist(n,INT_MAX);
        vector<long long>  cnt(n,0);
        cnt[0]=1;
        set<pair<int,int>> st;
        st.insert({0,0});
        while(!st.empty()){
            auto x = *st.begin();
            int distance=x.first;
            int val = x.second;
            st.erase(x);
            for(auto node:adj[val]){
                if(dist[node.first]>dist[val]+node.second){
                    st.erase({dist[node.first],node.first});
                    dist[node.first]=dist[val]+node.second;
                    cnt[node.first]=cnt[val]%mod;
                    st.insert({dist[node.first],node.first});
                }
                else if(dist[node.first]==dist[val]+node.second){
                    cnt[node.first] = (cnt[node.first]+cnt[val])%mod;
                }
            }
        }
        return cnt[n-1];
    }
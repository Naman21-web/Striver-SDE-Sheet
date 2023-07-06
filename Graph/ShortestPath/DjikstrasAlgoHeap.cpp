vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V,INT_MAX);
        dist[S]=0;
        
        pq.push({0,S});
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            if(dist[x.second]<x.first) continue;
            for(auto node:adj[x.second]){
                if(dist[node[0]]>dist[x.second]+node[1]){
                    dist[node[0]]=dist[x.second]+node[1];
                    pq.push({dist[node[0]],node[0]});
                }
            }
        }
        for(int i=0;i<V;i++){
            if(dist[i]==INT_MAX) dist[i]=-1;
        }
        return dist;
    }
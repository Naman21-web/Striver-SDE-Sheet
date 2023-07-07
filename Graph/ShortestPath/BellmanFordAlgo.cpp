vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        vector<int> dist(V,1e8);
        dist[S]=0;
        //Fot n-1 iterations
        for(int i=1;i<V;i++){
            for(auto edge:edges){
                if(dist[edge[1]]>dist[edge[0]]+edge[2]){
                    dist[edge[1]]=dist[edge[0]]+edge[2];
                }
            }
        }

        //if update occours in nth iteration that means -ve cycle present
        for(auto edge:edges){
            if(dist[edge[1]]>dist[edge[0]]+edge[2]){
                    return {-1};
                }
        }
        return dist;
    }
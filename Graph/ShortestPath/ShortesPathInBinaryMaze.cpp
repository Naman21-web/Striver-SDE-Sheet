int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        if(source==destination) return 0;
        int destx=destination.first;
        int desty=destination.second;
        if(grid[destx][desty]==0) return -1;
        vector<int> x={1,-1,0,0};
        vector<int> y={0,0,1,-1};
        int n=grid.size(),m=grid[0].size();
        set<pair<pair<int,int>,int>> st;
        vector<vector<int>> dist(n,vector<int> (m,INT_MAX));
        dist[source.first][source.second]=0;
        st.insert({source,0});
        while(!st.empty()){
            auto node = *st.begin();
            st.erase(node);
            int row = node.first.first;
            int col = node.first.second;
            int distance = node.second;
            for(int k=0;k<4;k++){
                int dx = row+x[k];
                int dy = col+y[k];
                if(dx>=0 && dy>=0 && dx<n && dy<m && grid[dx][dy]==1){
                    if(dist[dx][dy]>1+distance){
                        st.erase({{dx,dy},dist[dx][dy]});
                        dist[dx][dy] =1+distance;
                        st.insert({{dx,dy},dist[dx][dy]});
                    }
                }
            }
        }
        if(dist[destx][desty]==INT_MAX)return -1;
        return dist[destx][desty]; 
    }
int MinimumEffort(vector<vector<int>>& grid) {
        // Code here
        vector<int> x={1,-1,0,0};
        vector<int> y={0,0,1,-1};
        int n=grid.size(),m=grid[0].size();
        set<pair<int,pair<int,int>>> st;
        vector<vector<int>> dist(n,vector<int> (m,INT_MAX));
        dist[0][0]=0;
        st.insert({0,{0,0}});
        while(!st.empty()){
            auto node = *st.begin();
            st.erase(node);
            int row = node.second.first;
            int col = node.second.second;
            int distance = node.first;
            // cout<<row<<col<<distance<<" ";
            for(int k=0;k<4;k++){
                int dx = row+x[k];
                int dy = col+y[k];
                if(dx>=0 && dy>=0 && dx<n && dy<m){
                    if(dist[dx][dy]>max(distance,abs(grid[dx][dy]-grid[row][col]))){
                        // st.erase({{dx,dy},dist[dx][dy]});
                        st.erase({dist[dx][dy],{dx,dy}});
                        dist[dx][dy] = max(distance,abs(grid[dx][dy]-grid[row][col]));
                        // st.insert({{dx,dy},dist[dx][dy]});
                        st.insert({dist[dx][dy],{dx,dy}});
                    }
                }
            }
        }
        if(dist[n-1][m-1]==INT_MAX)return -1;
        return dist[n-1][m-1]; 
    }
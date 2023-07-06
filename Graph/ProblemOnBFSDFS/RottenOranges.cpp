int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        vector<int> x={1,-1,0,0};
        vector<int> y={0,0,1,-1};
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) {vis[i][j]=1;q.push({i,j});}
            }
        }
        int cnt=-1;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                int currx=q.front().first;
                int curry=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    dx = currx + x[k];
                    dy = curry + y[k];
                    if(dx>=0 && dy>=0 && dx<n && dy<m && !vis[dx][dy] && grid[dx][dy]==1){
                        vis[dx][dy]=1;
                        q.push({dx,dy});
                    }
                }
            }
            cnt++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return cnt;
    }
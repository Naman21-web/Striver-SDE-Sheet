vector<int> x = {1,-1,0,0};
    vector<int> y = {0,0,1,-1};
    void bfs(int i,int j,int n,int m,vector<vector<char>> &grid,vector<vector<int>> &vis){
        int cnt=0;
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j]=1;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int dx = row+x[k];
                int dy = col+y[k];
                if(dx>=0 && dy>=0 && dx<n && dy<m && !vis[dx][dy] && grid[dx][dy]=='O'){
                    vis[dx][dy]=1;
                    q.push({dx,dy});
                }
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> grid)
    {
        // code here
        int ans=0;
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            if(!vis[i][0] && grid[i][0]=='O') bfs(i,0,n,m,grid,vis);
            if(!vis[i][m-1] && grid[i][m-1]=='O') bfs(i,m-1,n,m,grid,vis);
        }
        for(int j=1;j<m-1;j++){
            if(!vis[0][j] && grid[0][j]=='O') bfs(0,j,n,m,grid,vis);
            if(!vis[n-1][j] && grid[n-1][j]=='O') bfs(n-1,j,n,m,grid,vis);
        }
        vector<vector<char>> result=grid;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(result[i][j]=='O' && !vis[i][j]) result[i][j]='X';
            }
        }
        return result;
    }
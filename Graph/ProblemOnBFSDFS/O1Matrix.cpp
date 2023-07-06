vector<vector<int>> bfs(vector<vector<int>> &grid,int n,int m){
        vector<vector<int>> ans(n,vector<int> (m));
        vector<vector<int>> vis(n,vector<int> (m,0));
        // int cnt=0;
        vector<int> x={1,-1,0,0};
        vector<int> y={0,0,1,-1};
        queue<pair<int,int>> q;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(grid[row][col]==1){
                    ans[row][col]=0;
                    vis[row][col]=1;
                    q.push({row,col});
                }
            }
        }
        int curr=1;
        while(!q.empty()){
            int qsize=q.size();
            for(int i=0;i<qsize;i++){
                int currx = q.front().first;
                int curry = q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int dx = currx + x[k];
                    int dy = curry + y[k];
                    if(dx>=0 && dy>=0 && dx<n && dy<m && !vis[dx][dy] && grid[dx][dy]==0){
                        // if(grid[dx][dy]==1) return abs(dx-i)+abs(dy-j);
                        vis[dx][dy]=1;
                        ans[dx][dy]=curr;
                        q.push({dx,dy});
                    }
                }
            }
            curr++;
        }
        return ans;
    }
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n=grid.size(),m=grid[0].size();
	   // vector<vector<int>> ans(n,vector<int> (m));
	   // for(int i=0;i<n;i++){
	   //     for(int j=0;j<m;j++){
	   //         if(grid[i][j]==1) ans[i][j]=0;
	   //         else{
	   //             ans[i][j] = bfs(i,j,grid,n,m);
	   //         }
	   //     }
	   // }
	    return bfs(grid,n,m);
	}
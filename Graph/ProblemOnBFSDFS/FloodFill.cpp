vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n=image.size(),m=image[0].size();
        if(image[sr][sc]==newColor) return image;
        queue<pair<int,int>> q;
        vector<int> x={1,-1,0,0};
        vector<int> y={0,0,-1,1};
        vector<vector<int>> vis(n,vector<int> (m,0));
        int oldColor=image[sr][sc];
        image[sr][sc]=newColor;
        q.push({sr,sc});
        vis[sr][sc]=1;
        while(!q.empty()){
            int currx=q.front().first;
            int curry=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int dx = currx + x[k];
                int dy = curry + y[k];
                if(dx>=0 && dy>=0 && dx<n && dy<m && !vis[dx][dy] && image[dx][dy]==oldColor){
                    vis[dx][dy]=1;
                    q.push({dx,dy});
                    image[dx][dy]=newColor;
                }
            }
        }
        return image;
    }
bool search(int i,int j,int a,int n,int m,vector<vector<int>> &vis,vector<vector<char>>& board,string word,vector<int> &x,vector<int> &y){
        if(a==word.size()) return true;
        bool ans=false;
        for(int k=0;k<4;k++){
            int dx = i+x[k];
            int dy = j+y[k];
            if(dx>=0 && dy>=0 && dx<n && dy<m && !vis[dx][dy] && board[dx][dy]==word[a]){
                vis[dx][dy]=true;
                ans = ans || search(dx,dy,a+1,n,m,vis,board,word,x,y);
                vis[dx][dy]=false;
                if(ans==true) break;
            }
        }
        return ans;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        vector<int> x={1,-1,0,0};
        vector<int> y={0,0,1,-1};
        int n=board.size(),m=board[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        bool ans=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    vis[i][j]=true;
                    ans = ans || search(i,j,1,n,m,vis,board,word,x,y);
                    vis[i][j]=false;
                    if(ans==true) break;
                }
            }
        }
        return ans;
    }
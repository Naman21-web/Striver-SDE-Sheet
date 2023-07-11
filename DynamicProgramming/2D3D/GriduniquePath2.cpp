int mod=1e9+7;
// int unique(int i,int j,int n,int m,vector<vector<int>>& mat){
// 	if(i>=n || j>=m) return 0;
//     if(mat[i][j]==-1) return 0;
// 	if(i==n-1 && j==m-1) return 1;
// 	return ((unique(i+1,j,n,m,mat)%mod) + (unique(i,j+1,n,m,mat)%mod))%mod;
// }

// int unique(int i,int j,int n,int m,vector<vector<int>>& mat,vector<vector<int>> &dp){
// 	if(i>=n || j>=m) return 0;
//     if(mat[i][j]==-1) return 0;
// 	if(i==n-1 && j==m-1) return 1;
//     if(dp[i][j]!=-1) return dp[i][j];
// 	return dp[i][j]=((unique(i+1,j,n,m,mat,dp)%mod) + (unique(i,j+1,n,m,mat,dp)%mod))%mod;
// }

int unique(int i,int j,int n,int m,vector<vector<int>>& mat,vector<vector<int>> &dp){
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(i==n-1 && j==m-1) dp[i][j]=1;
            else if(mat[i][j]==-1) dp[i][j]=0;
            else{
                dp[i][j] = ((dp[i+1][j]%mod)+(dp[i][j+1]%mod))%mod;
            }
        }
    }
    return dp[0][0]%mod;
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    // vector<vector<int>> dp(n,vector<int> (m,-1));
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    return unique(0,0,n,m,mat,dp)%mod;
}
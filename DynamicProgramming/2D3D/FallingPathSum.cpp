#include <bits/stdc++.h> 
// int maxSum(int i,int j,int n,int m,vector<vector<int>> &matrix){
//     if(j<0 || j>=m) return -1e9;
//     if(i==n-1) return matrix[n-1][j];

//     int down = maxSum(i+1,j,n,m,matrix);
//     int downl = maxSum(i+1,j-1,n,m,matrix);
//     int downr = maxSum(i+1,j+1,n,m,matrix);

//     return matrix[i][j]+max({down,downl,downr});
// }

// int maxSum(int i,int j,int n,int m,vector<vector<int>> &matrix,vector<vector<int>> &dp){
//     if(j<0 || j>=m) return -1e9;
//     if(i==n-1) return matrix[n-1][j];
//     if(dp[i][j]!=-1) return dp[i][j];
//     int down = maxSum(i+1,j,n,m,matrix,dp);
//     int downl = maxSum(i+1,j-1,n,m,matrix,dp);
//     int downr = maxSum(i+1,j+1,n,m,matrix,dp);
    
//     return dp[i][j]=matrix[i][j]+max({down,downl,downr});
// }

int maxSum(int n,int m,vector<vector<int>> &matrix,vector<vector<int>> &dp){
    for(int j=0;j<m;j++) dp[n-1][j]=matrix[n-1][j];
    for(int i=n-2;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            int downl=-1e9,down=-1e9,downr=-1e9;
            down = dp[i+1][j];
            if(j>0)downl = dp[i+1][j-1];
            if(j<m-1)downr = dp[i+1][j+1];
            dp[i][j]=matrix[i][j]+max({down,downl,downr});
        }
    }
    int maxi=INT_MIN;
    for(int j=0;j<m;j++){
        maxi = max(maxi,dp[0][j]);
    }
    return maxi;
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n=matrix.size();int m=matrix[0].size();
    // vector<vector<int>> dp(n,vector<int> (m,-1));
    // int maxi=INT_MIN;
    // for(int i=0;i<m;i++){
        // maxi = max(maxi,maxSum(0,i,n,m,matrix,dp));
    // }
    vector<vector<int>> dp(n,vector<int> (m,0));
    return maxSum(n,m,matrix,dp);
}
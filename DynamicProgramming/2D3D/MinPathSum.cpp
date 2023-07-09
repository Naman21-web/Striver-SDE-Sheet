#include <bits/stdc++.h> 
// int minSum(int i,int j,int n,int m,vector<vector<int>> &grid){
//     if(i==n-1 && j==m-1) return grid[i][j];
//     if(i>=n || j>=m) return 1e9;
//     int right = minSum(i,j+1,n,m,grid);
//     int down = minSum(i+1,j,n,m,grid);
//     return grid[i][j]+min(right,down);
// }

// int minSum(int i,int j,int n,int m,vector<vector<int>> &grid,vector<vector<int>> dp){
//     if(i==n-1 && j==m-1) return grid[i][j];
//     if(i>=n || j>=m) return 1e9;
//     if(dp[i][j]!=-1) return dp[i][j];
//     int right = minSum(i,j+1,n,m,grid,dp);
//     int down = minSum(i+1,j,n,m,grid,dp);
//     return dp[i][j]=grid[i][j]+min(right,down);
// }

// int minSum(int n,int m,vector<vector<int>> &grid,vector<vector<int>> dp){
//     for(int i=n-1;i>=0;i--){
//         for(int j=m-1;j>=0;j--){
//             if(i==n-1 && j==m-1)dp[i][j]=grid[i][j];
//             else{
//                 int right = dp[i][j+1];
//                 int down = dp[i+1][j];
//                 dp[i][j] = grid[i][j]+min(right,down);
//             }
//         }
//     }
//    return dp[0][0];
// }

int minSum(int n,int m,vector<vector<int>> &grid){
    vector<int> next(m+1,1e9),curr(m+1,1e9);
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(i==n-1 && j==m-1)curr[j]=grid[i][j];
            else{
                int right = curr[j+1];
                int down = next[j];
                curr[j] = grid[i][j]+min(right,down);
            }
        }
        next=curr;
    }
   return next[0];
}

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n=grid.size(),m=grid[0].size();
    // vector<vector<int>> dp(n,vector<int> (m,-1));
    // vector<vector<int>> dp(n+1,vector<int> (m+1,1e9));
    return minSum(n,m,grid);
}
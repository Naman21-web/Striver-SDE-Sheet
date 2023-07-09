#include <bits/stdc++.h>
vector<int> y={-1,0,1}; 
// int maxChoc(int i,int j1,int j2,int r,int c,vector<vector<int>> &grid){
//     if(j1<0 || j1>=c || j2<0 || j2>=c) return -1e9;
//     if(i==r-1){
//         if(j1==j2) return grid[i][j1];
//         return grid[i][j1]+grid[i][j2];
//     }
//     int ans=INT_MIN;
//     for(int k=0;k<3;k++){
//         for(int l=0;l<3;l++){
//             int newj1 = j1+y[k];
//             int newj2 = j2+y[l];
//             ans=max(ans,maxChoc(i+1,newj1,newj2,r,c,grid));
//         }
//     }
//     if(j1!=j2) return ans+grid[i][j1]+grid[i][j2];
//     return ans+grid[i][j2];
// }

// int maxChoc(int i,int j1,int j2,int r,int c,vector<vector<int>> &grid,vector<vector<vector<int>>> dp){
//     if(j1<0 || j1>=c || j2<0 || j2>=c) return -1e9;
//     if(i==r-1){
//         if(j1==j2) return grid[i][j1];
//         return grid[i][j1]+grid[i][j2];
//     }
//     if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
//     int ans=INT_MIN;
//     for(int k=0;k<3;k++){
//         for(int l=0;l<3;l++){
//             int newj1 = j1+y[k];
//             int newj2 = j2+y[l];
//             ans=max(ans,maxChoc(i+1,newj1,newj2,r,c,grid,dp));
//         }
//     }
//     if(j1!=j2) return dp[i][j1][j2]=ans+grid[i][j1]+grid[i][j2];
//     return dp[i][j1][j2]=ans+grid[i][j2];
// }

// int maxChoc(int r,int c,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp){
//     int ans=INT_MIN;
//     for(int j1=0;j1<c;j1++){
//         for(int j2=0;j2<c;j2++){
//             if(j1==j2) dp[r-1][j1][j2]= grid[r-1][j1];
//             else dp[r-1][j1][j2]=grid[r-1][j1]+grid[r-1][j2];
//         }
//     }
//     for(int i=r-2;i>=0;i--){
//         for(int j1=c-1;j1>=0;j1--){
//             for(int j2=0;j2<c;j2++){
//                 int ans=INT_MIN;
//                 for(int k=0;k<3;k++){
//                     for(int l=0;l<3;l++){
//                         int newj1 = j1+y[k];
//                         int newj2 = j2+y[l];
//                         int resofthisiter=-1e9;
//                         if(newj1>=0 && newj1<c && newj2>=0 && newj2<c) resofthisiter=dp[i+1][newj1][newj2];
//                         ans=max(ans,resofthisiter);
//                     }
//                 }
//                 if(j1!=j2) dp[i][j1][j2] = ans+grid[i][j1]+grid[i][j2];
//                 else  dp[i][j1][j2] = ans+grid[i][j2];
//             }
//         }
//     }
//     return dp[0][0][c-1];
// }

int maxChoc(int r,int c,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp){
    vector<vector<int>> prev(c,vector<int> (c,0)),curr(c,vector<int> (c,0));
    for(int j1=0;j1<c;j1++){
        for(int j2=0;j2<c;j2++){
            if(j1==j2) prev[j1][j2]= grid[r-1][j1];
            else prev[j1][j2]=grid[r-1][j1]+grid[r-1][j2];
        }
    }
    for(int i=r-2;i>=0;i--){
        for(int j1=c-1;j1>=0;j1--){
            for(int j2=0;j2<c;j2++){
                int ans=INT_MIN;
                for(int k=0;k<3;k++){
                    for(int l=0;l<3;l++){
                        int newj1 = j1+y[k];
                        int newj2 = j2+y[l];
                        int resofthisiter=-1e9;
                        if(newj1>=0 && newj1<c && newj2>=0 && newj2<c) resofthisiter=prev[newj1][newj2];
                        ans=max(ans,resofthisiter);
                    }
                }
                if(j1!=j2) curr[j1][j2] = ans+grid[i][j1]+grid[i][j2];
                else  curr[j1][j2] = ans+grid[i][j2];
            }
        }
        prev=curr;
    }
    return prev[0][c-1];
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    // vector<vector<vector<int>>> dp(r,vector<vector<int>> (c,vector<int> (c,-1)));
    vector<vector<vector<int>>> dp(r,vector<vector<int>> (c,vector<int> (c,0)));
    return maxChoc(r,c,grid,dp);
}
#include <bits/stdc++.h> 
// int maxVal(int i,int n,int w,vector<int> &profit, vector<int> &weight){
//     if(i==n) return 0;
//     int take=0;
//     if(weight[i]<=w) take = profit[i]+maxVal(i,n,w-weight[i],profit,weight);
//     int notTake = maxVal(i+1,n,w,profit,weight);
//     return max(take,notTake);
// }

// int maxVal(int i,int n,int w,vector<int> &profit, vector<int> &weight,vector<vector<int>> &dp){
//     if(i==n) return 0;
//     if(dp[i][w]!=-1) return dp[i][w];
//     int take=0;
//     if(weight[i]<=w) take = profit[i]+maxVal(i,n,w-weight[i],profit,weight,dp);
//     int notTake = maxVal(i+1,n,w,profit,weight,dp);
//     return dp[i][w]=max(take,notTake);
// }

int maxVal(int n,int w,vector<int> &profit, vector<int> &weight,vector<vector<int>> &dp){
    for(int i=n-1;i>=0;i--){
        for(int wt=0;wt<=w;wt++){
             int take=0;
            if(weight[i]<=wt) take = profit[i]+dp[i][wt-weight[i]];
            int notTake = dp[i+1][wt];
            dp[i][wt]=max(take,notTake);
        }
    }
    return dp[0][w];
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    // vector<vector<int>> dp(n,vector<int> (w+1,-1));
    vector<vector<int>> dp(n+1,vector<int> (w+1,0));
    return maxVal(n,w,profit,weight,dp);
}

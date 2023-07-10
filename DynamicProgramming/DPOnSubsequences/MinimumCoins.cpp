#include <bits/stdc++.h> 
// int minCoins(int i,int n,int x,vector<int> &num){
//     if(x==0) return 0;
//     if(i==n) return 1e9;
//     int take=1e9;
//     if(num[i]<=x) take = 1+minCoins(i,n,x-num[i],num);
//     int notTake = minCoins(i+1,n,x,num);
//     return min(take,notTake);
// }

// int minCoins(int i,int n,int x,vector<int> &num,vector<vector<int>> &dp){
//     if(x==0) return 0;
//     if(i==n) return 1e9;
//     if(dp[i][x]!=-1) return dp[i][x];
//     int take=1e9;
//     if(num[i]<=x) take = 1+minCoins(i,n,x-num[i],num,dp);
//     int notTake = minCoins(i+1,n,x,num,dp);
//     return dp[i][x]=min(take,notTake);
// }

int minCoins(int n,int x,vector<int> &num,vector<vector<int>> &dp){
    // if(x==0) return 0;
    // if(i==n) return 1e9;
    // if(dp[i][x]!=-1) return dp[i][x];
    for(int i=0;i<n;i++) dp[i][0]=0;
    for(int i=n-1;i>=0;i--){
        for(int val=1;val<=x;val++){
            int take=1e9;
            if(num[i]<=val) take = 1+dp[i][val-num[i]];
            int notTake = dp[i+1][val];
            dp[i][val]=min(take,notTake);
        }
    }
    return dp[0][x];
}

int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n=num.size();
    // vector<vector<int>> dp(n,vector<int> (x+1,-1));
    vector<vector<int>> dp(n+1,vector<int> (x+1,1e9));
    int ans= minCoins(n,x,num,dp);
    if(ans>1e8) return -1;
    return ans;
}
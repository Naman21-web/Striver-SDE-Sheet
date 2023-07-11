#include <bits/stdc++.h> 
// int findprof(int i,vector<int>& prices,int n,bool buy,int cap){
//     if(cap==0) return 0;
//     if(i==n) return 0;
//     if(buy){
//         return max(-prices[i]+findprof(i+1,prices,n,!buy,cap),findprof(i+1,prices,n,buy,cap));
//     }
//     else{
//         return max(prices[i]+findprof(i+1,prices,n,!buy,cap-1),findprof(i+1,prices,n,buy,cap));
//     }
// }

// int findprof(int i,vector<int>& prices,int n,bool buy,int cap,vector<vector<vector<int>>> &dp){
//     if(cap==0) return 0;
//     if(i==n) return 0;
//     if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
//     if(buy){
//         return dp[i][buy][cap]=max(-prices[i]+findprof(i+1,prices,n,!buy,cap,dp),findprof(i+1,prices,n,buy,cap,dp));
//     }
//     else{
//         return dp[i][buy][cap]=max(prices[i]+findprof(i+1,prices,n,!buy,cap-1,dp),findprof(i+1,prices,n,buy,cap,dp));
//     }
// }

int findprof(vector<int>& prices,int n,vector<vector<vector<int>>> &dp){
    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<2;buy++){
            for(int cap=1;cap<3;cap++){
                if(buy){
                    dp[i][buy][cap] = max(-prices[i]+dp[i+1][!buy][cap],dp[i+1][buy][cap]);
                }
                else{
                    dp[i][buy][cap] = max(prices[i]+dp[i+1][!buy][cap-1],dp[i+1][buy][cap]);
                }
            }
        }
    }
    return dp[0][true][2];
}

int maxProfit(vector<int>& prices, int n)
{
    // Write your code here.
    // vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int> (3,-1)));
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int> (3,0)));
    return findprof(prices,n,dp);
}
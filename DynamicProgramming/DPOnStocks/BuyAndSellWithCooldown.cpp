#include <bits/stdc++.h> 

// int findprof(vector<int>& prices,int n,vector<vector<vector<int>>> &dp,int k){
//     for(int i=n-1;i>=0;i--){
//         for(int buy=0;buy<2;buy++){
//             for(int cap=1;cap<k+1;cap++){
//                 if(buy){
//                     dp[i][buy][cap] = max(-prices[i]+dp[i+1][!buy][cap],dp[i+1][buy][cap]);
//                 }
//                 else{
//                     dp[i][buy][cap] = max(prices[i]+dp[i+1][!buy][cap-1],dp[i+1][buy][cap]);
//                 }
//             }
//         }
//     }
//     return dp[0][true][k];
// }

int findprof(vector<int>& prices,int n,vector<vector<vector<int>>> &dp,int k){
    vector<vector<int>> curr(2,vector<int> (k+1,0)),next(2,vector<int> (k+1,0));
    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<2;buy++){
            for(int cap=1;cap<k+1;cap++){
                if(buy){
                    curr[buy][cap] = max(-prices[i]+next[!buy][cap],next[buy][cap]);
                }
                else{
                    curr[buy][cap] = max(prices[i]+next[!buy][cap-1],next[buy][cap]);
                }
            }
        }
        next=curr;
    }
    return next[true][k];
}

int maximumProfit(vector<int> &prices, int n, int k)
{
    // Write your code here.
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int> (k+1,0)));
    return findprof(prices,n,dp,k);
}

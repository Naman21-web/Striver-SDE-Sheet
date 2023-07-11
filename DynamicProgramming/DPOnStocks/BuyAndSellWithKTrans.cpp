#include <bits/stdc++.h> 
// int buysellwithcooldown(int i,int n,vector<int> &prices,bool buy){
//     if(i>=n) return 0;
//     if(buy){
//         return max(-prices[i]+buysellwithcooldown(i+1,n,prices,!buy),buysellwithcooldown(i+1,n,prices,buy));
//     }
//     else{
//         return max(prices[i]+buysellwithcooldown(i+2,n,prices,!buy),buysellwithcooldown(i+1,n,prices,buy));
//     }
// }

// int buysellwithcooldown(int i,int n,vector<int> &prices,bool buy,vector<vector<int>> &dp){
//     if(i>=n) return 0;
//     if(dp[i][buy]!=-1) return dp[i][buy];
//     if(buy){
//         return dp[i][buy]=max(-prices[i]+buysellwithcooldown(i+1,n,prices,!buy,dp),buysellwithcooldown(i+1,n,prices,buy,dp));
//     }
//     else{
//         return dp[i][buy]=max(prices[i]+buysellwithcooldown(i+2,n,prices,!buy,dp),buysellwithcooldown(i+1,n,prices,buy,dp));
//     }
// }

// int buysellwithcooldown(int n,vector<int> &prices,vector<vector<int>> &dp){
//     for(int i=n-1;i>=0;i--){
//         for(int buy=0;buy<2;buy++){
//             if(buy){
//                 dp[i][buy]=max(-prices[i]+dp[i+1][!buy],dp[i+1][buy]);
//             }
//             else{
//                 dp[i][buy] = max(prices[i]+dp[i+2][!buy],dp[i+1][buy]);
//             }
//         }
//     }
//     return dp[0][1];
// }

int buysellwithcooldown(int n,vector<int> &prices){
    vector<int> curr(2,0),next(2,0),nextdouble(2,0);
    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<2;buy++){
            if(buy){
                curr[buy]=max(-prices[i]+next[!buy],next[buy]);
            }
            else{
                curr[buy] = max(prices[i]+nextdouble[!buy],next[buy]);
            }
        }
        nextdouble=next;
        next=curr;
    }
    return next[1];
}

int stockProfit(vector<int> &prices){
    // Write your code here.
    int n=prices.size();
    // vector<vector<int>> dp(n,vector<int> (2,-1));
    // vector<vector<int>> dp(n+2,vector<int> (2,0));
    return buysellwithcooldown(n,prices);
}
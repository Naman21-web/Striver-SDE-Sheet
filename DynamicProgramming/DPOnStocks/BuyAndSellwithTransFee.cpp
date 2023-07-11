#include <bits/stdc++.h> 
int getprofit(int n,vector<int> &values,vector<vector<int>> &dp,int fee){
    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<2;buy++){
            if(buy){
                dp[i][buy]=max(-values[i]+dp[i+1][!buy],dp[i+1][buy]);
            } else {
              dp[i][buy] = max(-fee+values[i] + dp[i + 1][!buy], dp[i + 1][buy]);
            }
        }
    }
    return dp[0][true];
}
int maximumProfit(int n, int fee, vector<int> &prices) {
    // Write your code here.
    vector<vector<int>> dp(n+1,vector<int> (2,0));
    return getprofit(n,prices,dp,fee);
}

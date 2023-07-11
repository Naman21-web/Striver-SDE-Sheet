// long getprofit(int i,int n,long *values,bool buy){
//     if(i==n) return 0;
//     if(buy){
//         return max(-values[i]+getprofit(i+1,n,values,!buy),getprofit(i+1,n,values,buy));
//     }
//     else{
//         return max(values[i]+getprofit(i+1,n,values,!buy),getprofit(i+1,n,values,buy));
//     }
// }

// long getprofit(int i,int n,long *values,bool buy,vector<vector<int>> &dp){
//     if(i==n) return 0;
//     if(dp[i][buy]!=-1) return dp[i][buy];
//     if(buy){
//         return dp[i][buy]=max(-values[i]+getprofit(i+1,n,values,!buy,dp),getprofit(i+1,n,values,buy,dp));
//     }
//     else{
//         return dp[i][buy]=max(values[i]+getprofit(i+1,n,values,!buy,dp),getprofit(i+1,n,values,buy,dp));
//     }
// }

long getprofit(int i,int n,long *values,bool buy,vector<vector<int>> &dp){
    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<2;buy++){
            if(buy){
                dp[i][buy]=max(-values[i]+dp[i+1][!buy],dp[i+1][buy]);
            } else {
              dp[i][buy] = max(values[i] + dp[i + 1][!buy], dp[i + 1][buy])
            }
        }
    }
    return dp[0][true];
}

long getMaximumProfit(long *values, int n)
{
    //Write your code here
    // vector<vector<int>> dp(n,vector<int> (2,-1));
    vector<vector<int>> dp(n+1,vector<int> (2,0));
    return getprofit(0,n,values,true);
}
#include <bits/stdc++.h> 
int mod=1e9+7;
// int countways(int i,int n,vector<int> &dp){
//     if(i==n) return 1;
//     if(i>n) return 0;
//     if(dp[i]!=-1) return dp[i];
//     return dp[i]=((countways(i+1,n,dp)%mod)+(countways(i+2,n,dp)%mod))%mod;
// }
int countways(int n,vector<int> &dp){
    dp[n]=1;
    for(int i=n-1;i>=0;i--){
        dp[i] = ((dp[i+1]%mod)+(dp[i+2]%mod))%mod;
    }
    return dp[0];
}
int countDistinctWays(int nStairs) {
    //  Write your code here.
    // vector<int> dp(nStairs,-1);
    vector<int> dp(nStairs+2,0);
    return countways(nStairs,dp)%mod;
}
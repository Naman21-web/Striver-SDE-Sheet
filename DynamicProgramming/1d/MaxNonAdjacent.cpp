#include <bits/stdc++.h> 
// int maxSum(int i,int n,vector<int> &nums,vector<int> &dp){
//     if(i>=n) return 0;
//     if(dp[i]!=-1) return dp[i];
//     int take = nums[i]+maxSum(i+2,n,nums,dp);
//     int notTake = maxSum(i+1,n,nums,dp);
//     return dp[i]=max(take,notTake);
// }

int maxSum(int n,vector<int> &nums,vector<int> &dp){
    for(int i=n-1;i>=0;i--){
        int take = nums[i]+dp[i+2];
        int notTake = dp[i+1];
        dp[i]=max(take,notTake);
    }
    return dp[0];
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    // vector<int> dp(n,-1);
    vector<int> dp(n+2,0);
    return maxSum(n,nums,dp);
}
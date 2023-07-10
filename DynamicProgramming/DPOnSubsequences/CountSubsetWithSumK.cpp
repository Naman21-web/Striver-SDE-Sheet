#include <bits/stdc++.h>
using namespace std;
// int ways(int i,vector<int> &nums,int tar,vector<vector<int>> &dp){
//     if(i==0){
//         if(tar==0 && nums[0]==0) return 2;
//         else if(tar==0 && nums[0]!=0) return 1;
//         else if(nums[0]==tar) return 1;
//         else return 0;
//     }
//     if(dp[i][tar]!=-1) return dp[i][tar];
//     int notPick = ways(i-1,nums,tar,dp);
//     int pick=0;
//     if(tar>=nums[i]) pick =ways(i-1,nums,tar-nums[i],dp);
//     return dp[i][tar]=pick+notPick;
//  }

int ways(int n,vector<int> &nums,int tar,vector<vector<int>> &dp){
        for(int i=1;i<n;i++) dp[i][0]=1;
        if(nums[0]==0) dp[0][0]=2;
        else dp[0][0]=1;
        if(nums[0]!=0 && nums[0]<=tar)dp[0][nums[0]]=1;
        for(int i=1;i<n;i++){
            for(int j=1;j<=tar;j++){
                 int notPick = dp[i-1][j];
                 int pick=0;
                 if(j>=nums[i]) pick =dp[i-1][j-nums[i]];
                 dp[i][j]=pick+notPick;
            }
        }
        return dp[n-1][tar];
}
int findWays(vector<int> &nums, int tar)
{
    // Write your code here.
    int n = nums.size();
    vector<vector<int>> dp(n,vector<int> (tar+1,0));
    return ways(n,nums,tar,dp);
}
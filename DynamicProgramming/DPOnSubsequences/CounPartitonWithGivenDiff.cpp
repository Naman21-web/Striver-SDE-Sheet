#include <bits/stdc++.h> 
int mod=1e9+7;
// int ways(int n,int target,vector<int> &arr,vector<vector<int>> &dp){
//     for(int i=1;i<n;i++) dp[i][0]=1;
//     if(arr[0]==0) dp[0][0]=2;
//     else dp[0][0]=1;
//     if(arr[0]!=0 && arr[0]<=target) dp[0][arr[0]]=1;
//     for(int i=1;i<n;i++){
//         for(int j=0;j<=target;j++){
//             int notPick = dp[i-1][j];
//             int pick = 0;
//             if(j>=arr[i]) pick = dp[i-1][j-arr[i]];
//             dp[i][j] = (pick+notPick)%mod;
//         }
//     }
//     return dp[n-1][target]%mod;
// }

int ways(int n,int target,vector<int> &arr,vector<vector<int>> &dp){
    vector<int> curr(target+1,0),prev(target+1,0);
    // for(int i=1;i<n;i++) dp[i][0]=1;
    if(arr[0]==0) prev[0]=2;
    else prev[0]=1;
    if(arr[0]!=0 && arr[0]<=target) prev[arr[0]]=1;
    for(int i=1;i<n;i++){
        curr[0]=1;
        for(int j=0;j<=target;j++){
            int notPick = prev[j];
            int pick = 0;
            if(j>=arr[i]) pick = prev[j-arr[i]];
            curr[j] = (pick+notPick)%mod;
        }
        prev=curr;
    }
    return prev[target]%mod;
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int sum=0;
    for(int i=0;i<n;i++) sum += arr[i];
    if(sum-d<0 || (sum-d)%2!=0) return 0;
    int target = (sum-d)/2;
    vector<vector<int>> dp(n,vector<int> (target+1,0));
    return ways(n,target,arr,dp);
}



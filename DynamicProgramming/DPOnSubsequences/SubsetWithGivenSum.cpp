#include <bits/stdc++.h> 
// bool subset(int i,int target,vector<int> &arr){
//     if(target==0) return true;
//     if(i==0) return arr[0]==target;
//     int take = subset(i-1,target-arr[i],arr);
//     int notTake = subset(i-1,target,arr);
//     return take || notTake; 
// }

// bool subset(int i,int target,vector<int> &arr,vector<vector<int>> &dp){
//     if(target==0) return true;
//     if(i==0) return arr[0]==target;
//     if(dp[i][target] != -1)return dp[i][target];
//     bool take=false;
//     if(target>=arr[i]) take= subset(i-1,target-arr[i],arr,dp);
//     bool notTake = subset(i-1,target,arr,dp);
//     return dp[i][target]=take || notTake; 
// }

// bool subset(int i,int k,vector<int> &arr,vector<vector<int>> &dp){
    
//     for(int i=0;i<arr.size();i++) dp[i][0]=1;
//     if(arr[0]<=k) dp[0][arr[0]]=1;
//     for(int i=1;i<arr.size();i++){
//         for(int target=1;target<=k;target++){
//             bool take=false;
//             if(target>=arr[i]) take= dp[i-1][target-arr[i]];
//             bool notTake = dp[i-1][target];
//             dp[i][target] = take || notTake;
//         }
//     }
//     return dp[n-1][k];
// }

bool subset(int k,vector<int> &arr){
    vector<int> curr(k+1,0),prev(k+1,0);
    if(arr[0]<=k) prev[arr[0]]=1;
    for(int i=1;i<arr.size();i++){
        curr[0]=1;
        for(int target=1;target<=k;target++){
            bool take=false;
            if(target>=arr[i]) take= prev[target-arr[i]];
            bool notTake = prev[target];
            curr[target] = take || notTake;
        }
        prev=curr;
    }
    return prev[k];
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    // vector<vector<int>> dp(n,vector<int> (k+1,0));
    return subset(k,arr);
}
#include <bits/stdc++.h> 
// int findmax(int i,int n,int k,vector<int> &num){
//     if(i==n) return 0;
//     int maxSum=INT_MIN,maxi=INT_MIN,len=0;
//     for(int j=i;j<min(n,i+k);j++){
//         maxi = max(maxi,num[j]);
//         len++;
//         int ans = (maxi*len) + findmax(j+1,n,k,num);
//         maxSum = max(maxSum,ans);
//     }
//     return maxSum;
// }

// int findmaxmemo(int i,int n,int k,vector<int> &num,vector<int> &dp){
//     if(i==n) return 0;
//     if(dp[i]!=-1) return dp[i];
//     int maxSum=INT_MIN,maxi=INT_MIN,len=0;
//     for(int j=i;j<min(n,i+k);j++){
//         maxi = max(maxi,num[j]);
//         len++;
//         int ans = (maxi*len) + findmaxmemo(j+1,n,k,num,dp);
//         maxSum = max(maxSum,ans);
//     }
//     return dp[i]=maxSum;
// }

int findmaxtab(int n,int k,vector<int> &num,vector<int> &dp){
    for(int i=n-1;i>=0;i--){
        int maxSum=INT_MIN,maxi=INT_MIN,len=0;
        for (int j = i; j < min(n, i + k); j++) {
          maxi = max(maxi, num[j]);
          len++;
          int ans = (maxi * len) + dp[j + 1];
          maxSum = max(maxSum, ans);
        }
        dp[i] = maxSum;
    }
    return dp[0];
}

int maximumSubarray(vector<int> &num, int k)
{
    // Write your code here.
    int n=num.size();
    vector<int> dp(n+1,0);
    return findmaxtab(n,k,num,dp);
}
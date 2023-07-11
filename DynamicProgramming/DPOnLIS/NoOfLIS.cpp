#include <bits/stdc++.h> 
int findNumberOfLIS(vector<int> &arr)
{
    // Write your code here.
    int n=arr.size();
    int maxi=1,sum=1;
    vector<int> cnt(n,1),dp(n,1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && dp[i]==1+dp[j]){
                cnt[i] += cnt[j];
            }
            else if(arr[i]>arr[j] && dp[i]<1+dp[j]){
                dp[i] = 1+dp[j];
                cnt[i] = cnt[j];
            }
        }
        if(dp[i]>=maxi){
            if(dp[i]>maxi)sum = cnt[i];
            else sum += cnt[i];
            maxi=dp[i];
        }
    }
    return sum;
}
#include <bits/stdc++.h> 
int countways(int n,int target,vector<int> &arr){
    vector<int> prev(target+1,0),curr(target+1,0);
    if(arr[0]==0) prev[0]=2;
    else prev[0]=1;
    if(arr[0]!=0 && arr[0]<=target) prev[arr[0]]=1;
    for(int i=1;i<n;i++){
        curr[0]=1;
        for(int sum=0;sum<=target;sum++){
            int take=0;
            if(arr[i]<=sum) take = prev[sum-arr[i]];
            int notTake = prev[sum];
            curr[sum] = take+notTake;
        }
        prev=curr;
    }
    return prev[target];
}
int targetSum(int n, int diff, vector<int>& arr) {
    // Write your code here.
    int sum=0;
    for(int i=0;i<n;i++) sum += arr[i];
    if(sum<diff || (sum-diff)%2!=0) return 0;
    int target = (sum-diff)/2;
    return countways(n,target,arr);
}

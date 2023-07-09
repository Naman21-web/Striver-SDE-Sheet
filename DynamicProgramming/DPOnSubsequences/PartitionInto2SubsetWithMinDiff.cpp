#include <bits/stdc++.h> 
int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	int sum=0;
	for(int i=0;i<n;i++){
		sum += arr[i];
	}
	// vector<vector<int>> dp(n,vector<int> (sum+1,0));
	// for(int i=0;i<n;i++) dp[i][0]=1;
	// if(arr[0]<=sum) dp[0][arr[0]]=1;
	// for(int i=1;i<n;i++){
	// 	for(int target=1;target<=sum;target++){
	// 		bool take=false;
	// 		if(arr[i]<=target) take = dp[i-1][target-arr[i]];
	// 		bool notTake = dp[i-1][target];
	// 		dp[i][target] = take || notTake;
	// 	}
	// }
	vector<int> prev(sum+1,0),curr(sum+1,0);
	prev[0]=1;
	if(arr[0]<=sum) prev[arr[0]]=1;
	for(int i=1;i<n;i++){
		curr[0]=1;
		for(int target=1;target<=sum;target++){
			bool take=false;
			if(arr[i]<=target) take = prev[target-arr[i]];
			bool notTake = prev[target];
			curr[target] = take || notTake;
		}
		prev=curr;
	}
	int diff=INT_MAX;
	for(int i=0;i<=sum/2;i++){
		if(prev[i]==true){
			int s1=i;
			int s2=sum-i;
			diff = min(diff,abs(s2-s1));
		}
	}
	return diff;
}

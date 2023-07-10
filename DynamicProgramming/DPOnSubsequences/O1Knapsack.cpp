#include <bits/stdc++.h> 
// int maxval(int i,vector<int> weight, vector<int> value, int n, int maxWeight){
// 	if(i==n) return 0;
// 	int take=0;
// 	if(weight[i]<=maxWeight) take = value[i]+maxval(i+1,weight,value,n,maxWeight-weight[i]);
// 	int notTake = maxval(i+1,weight,value,n,maxWeight);
// 	return max(take,notTake);
// }

// int maxval(int i,vector<int> weight, vector<int> value, int n, int maxWeight,vector<vector<int>> &dp){
// 	if(i==n) return 0;
// 	if(dp[i][maxWeight]!=-1) return dp[i][maxWeight];
// 	int take=0;
// 	if(weight[i]<=maxWeight) take = value[i]+maxval(i+1,weight,value,n,maxWeight-weight[i],dp);
// 	int notTake = maxval(i+1,weight,value,n,maxWeight,dp);
// 	return dp[i][maxWeight]=max(take,notTake);
// }

// int maxval(int i,vector<int> weight, vector<int> value, int n, int maxWeight,vector<vector<int>> &dp){
// 	if(i==n) return 0;
// 	if(dp[i][maxWeight]!=-1) return dp[i][maxWeight];
// 	int take=0;
// 	if(weight[i]<=maxWeight) take = value[i]+maxval(i+1,weight,value,n,maxWeight-weight[i],dp);
// 	int notTake = maxval(i+1,weight,value,n,maxWeight,dp);
// 	return dp[i][maxWeight]=max(take,notTake);
// }

// int maxval(vector<int> weight, vector<int> value, int n, int maxWeight,vector<vector<int>> &dp){
// 	for(int i=n-1;i>=0;i--){
// 		for(int wt=0;wt<=maxWeight;wt++){
// 			int take=0;
// 			if(weight[i]<=wt) take = value[i]+dp[i+1][wt-weight[i]];
// 			int notTake = dp[i+1][wt];
// 			dp[i][wt]=max(take,notTake);
// 		}
// 	}
// 	return dp[0][maxWeight];
// }

int maxval(vector<int> weight, vector<int> value, int n, int maxWeight){
	vector<int> prev(maxWeight+1,0),curr(maxWeight+1,0);
	for(int i=n-1;i>=0;i--){
		for(int wt=0;wt<=maxWeight;wt++){
			int take=0;
			if(weight[i]<=wt) take = value[i]+prev[wt-weight[i]];
			int notTake = prev[wt];
			curr[wt]=max(take,notTake);
		}
		prev=curr;
	}
	return prev[maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	// vector<vector<int>> dp(n,vector<int> (maxWeight+1,-1));
	// vector<vector<int>> dp(n+1,vector<int> (maxWeight+1,0));
	return maxval(weight,value,n,maxWeight);
}
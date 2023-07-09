#include <bits/stdc++.h> 
// int minPath(int i,int j,int n,vector<vector<int>> &triangle){
// 	if(i==n-1) return triangle[i][j];
// 	int down = minPath(i+1,j,n,triangle);
// 	int downright = minPath(i+1,j+1,n,triangle);
// 	return triangle[i][j]+min(down,downright);
// }

// int minPath(int i,int j,int n,vector<vector<int>> &triangle,vector<vector<int>> &dp){
// 	if(i==n-1) return triangle[i][j];
// 	if(dp[i][j]!=-1) return dp[i][j];
// 	int down = minPath(i+1,j,n,triangle,dp);
// 	int downright = minPath(i+1,j+1,n,triangle,dp);
// 	return dp[i][j]=triangle[i][j]+min(down,downright);
// }

// int minPath(int i,int j,int n,vector<vector<int>> &triangle,vector<vector<int>> &dp){
// 	for(int j=0;j<n;j++) dp[n-1][j] = triangle[n-1][j];
// 	for(int i=n-2;i>=0;i--){
// 		for(int j=i;j>=0;j--){
// 			int down = dp[i+1][j];
// 			int downright = dp[i+1][j+1];
// 			dp[i][j]=triangle[i][j]+min(down,downright);
// 		}
// 	}
// 	return dp[0][0];
// }

int minPath(int n,vector<vector<int>> &triangle){
	vector<int> next(n),curr(n);
	for(int j=0;j<n;j++) next[j] = triangle[n-1][j];
	for(int i=n-2;i>=0;i--){
		for(int j=i;j>=0;j--){
			int down = next[j];
			int downright = next[j+1];
			curr[j]=triangle[i][j]+min(down,downright);
		}
		next=curr;
	}
	return next[0];
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
	// vector<vector<int>> dp(n,vector<int> (n,-1));
	return minPath(n,triangle);
}
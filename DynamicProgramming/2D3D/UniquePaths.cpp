#include <bits/stdc++.h> 
// int unique(int i,int j,int m,int n,vector<vector<int>>& dp){
// 	if(i>=m || j>=n) return 0;
// 	if(i==m-1 && j==n-1) return 1;
// 	if(dp[i][j]!=-1) return dp[i][j];
// 	return dp[i][j]=unique(i+1,j,m,n,dp) + unique(i,j+1,m,n,dp);
// }

int unique(int m,int n,vector<vector<int>>& dp){
	for(int i=m-1;i>=0;i--){
		for(int j=n-1;j>=0;j--){
			if(i==m-1 && j==n-1) dp[i][j]=1;
			else{
				dp[i][j] = dp[i+1][j]+dp[i][j+1];
			}
		}
	}
	return dp[0][0];
	// return dp[i][j]=unique(i+1,j,m,n,dp) + unique(i,j+1,m,n,dp);
}

int uniquePaths(int m, int n) {
	// Write your code here.
	// vector<vector<int>> dp(m,vector<int> (n,-1));
	vector<vector<int>> dp(m+1,vector<int> (n+1,0));
	return unique(m,n,dp);
}
// int maxcost(int i,int n,vector<int> &price,int len){
// 	if(i==n) return 0;
// 	int take=0;
// 	if(len>=(i+1)) take = price[i]+maxcost(i,n,price,len-(i+1));
// 	int notTake = maxcost(i+1,n,price,len);
// 	return max(take,notTake);
// }

// int maxcost(int i,int n,vector<int> &price,int len,vector<vector<int>> &dp){
// 	if(i==n) return 0;
// 	if(dp[i][len]!=-1) return dp[i][len];
// 	int take=0;
// 	if(len>=(i+1)) take = price[i]+maxcost(i,n,price,len-(i+1),dp);
// 	int notTake = maxcost(i+1,n,price,len,dp);
// 	return dp[i][len]=max(take,notTake);
// }

int maxcost(int n,vector<int> &price,int len,vector<vector<int>> &dp){
	for(int i=n-1;i>=0;i--){
		for(int l=0;l<=len;l++){
			int take=0;
			if(l>=(i+1)) take = price[i]+dp[i][l-(i+1)];
			int notTake = dp[i+1][l];
			dp[i][l] = max(take,notTake);
		}
	}
	return dp[0][len];
}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	// vector<vector<int>> dp(n,vector<int> (n+1,-1));
	vector<vector<int>> dp(n+1,vector<int> (n+1,0));
	return maxcost(n,price,n,dp);
}


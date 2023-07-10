vector<vector<int>> lcstable(int n,int m,string &s1,string &s2){
	vector<vector<int>> dp(n+1,vector<int> (m+1,0));
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(s1[i-1]==s2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
			else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp;
}
string findLCS(int n, int m,string &s1, string &s2){
	// Write your code here.
	vector<vector<int>> dp;
	dp = lcstable(n,m,s1,s2);
	int i=n,j=m;
	string ans;
	while(i>0 && j>0){
		if(s1[i-1]==s2[j-1]) {ans += s1[i-1]; i--; j--;}
		else{
			if(dp[i-1][j]>dp[i][j-1]) i--;
			else j--;
		}
	}	
	reverse(ans.begin(),ans.end());
	return ans;
}
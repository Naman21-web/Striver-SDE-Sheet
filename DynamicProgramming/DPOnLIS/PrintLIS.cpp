vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) {
	// Write your code here
	vector<int> dp(n,1),hash(n);
	for(int i=0;i<n;i++) hash[i]=i;
	int maxi=1,maxidx=0;
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(arr[i]>arr[j] && 1+dp[j]>dp[i]){
				dp[i] = 1+dp[j];
				hash[i]=j;
			}
		}
		if(dp[i]>maxi){
			maxi=dp[i];
			maxidx=i;
		}
	}
	vector<int> ans(maxi);
	int idx=0;
	// maxi[idx++]=arr[maxidx];
	while(idx<maxi){
		ans[idx++]=arr[maxidx];
		maxidx = hash[maxidx];
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

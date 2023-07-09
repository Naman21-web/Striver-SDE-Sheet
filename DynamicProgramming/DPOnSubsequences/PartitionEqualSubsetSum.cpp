// bool subset(int i,int target,vector<int> &arr, int n){
// 	if(target==0) return 1;
// 	if(i==n) return 0;
// 	bool take=false;
// 	if(arr[i]<=target) take = subset(i+1,target-arr[i],arr,n);
// 	bool notTake = subset(i+1,target,arr,n);
// 	return take||notTake;
// }

bool subset(int i,int target,vector<int> &arr, int n,vector<vector<int>> &dp){
	if(target==0) return 1;
	if(i==n) return 0;
	if(dp[i][target] != -1) return dp[i][target];
	bool take=false;
	if(arr[i]<=target) take = subset(i+1,target-arr[i],arr,n,dp);
	bool notTake = subset(i+1,target,arr,n,dp);
	return dp[i][target]=take||notTake;
}
	

bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
	int sum = 0;//accumulate(arr.begin(),arr.end(),0);
	for(int i=0;i<n;i++) sum += arr[i];
	if(sum%2!=0) return 0;
	int target=sum/2;
	vector<vector<int>> dp(n,vector<int> (target+1,-1));
	return subset(0,target,arr,n,dp);
}

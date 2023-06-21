int mod=1e9+7;
	int generate(int i,int n,int arr[],int sum){
	    if(i==n){
	        if(sum==0) return 1;
	        return 0;
	    }
	    return ((long long)generate(i+1,n,arr,sum-arr[i])+generate(i+1,n,arr,sum))%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        return generate(0,n,arr,sum)%mod;
	}
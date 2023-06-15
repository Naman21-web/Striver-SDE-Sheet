long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long prod=1,res=INT_MIN;
	    for(int i=0;i<n;i++){
	        prod *= arr[i];
	        res=max(res,prod);
	        if(prod==0) prod=1;
	    }
	    prod=1;
	    for(int i=n-1;i>=0;i--){
	        prod *= arr[i];
	        res = max(res,prod);
	        if(prod==0) prod=1;
	    }
	    return res;
	}
int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int res=0,row=0;
	    for(int i=0;i<n;i++){
	        int lo=0,hi=m-1;
	        int ans=m;
	        while(lo<=hi){
	            int mid= lo + (hi-lo)/2;
	            if(arr[i][mid]==1){
	                ans=mid;
	                hi=mid-1;
	            }
	            else lo=mid+1;
	        }
	        int ones = m-ans;
	        if(ones>res){
	            res=ones;
	            row=i;
	        }
	    }
	    if(res==0) return -1;
	    return row;
	}
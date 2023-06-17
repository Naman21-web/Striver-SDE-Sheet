int NthRoot(int n, int m)
	{
	    // Code here.
	    if(n==1) return m;
	    long long lo=1,hi=sqrt(m);
	    while(lo<=hi){
	        long long int mid = lo + (hi-lo)/2;
	        long long x = 1;
	        for(long long int i=1;i<=n;i++){
	            x *= mid;
	            if(x>m) {break;}
	        }
	       // cout<<mid<<" "<<x<<" ";
	        if(x==m) return mid;
	        else if(x>m)hi=mid-1;
	        else lo=mid+1;
	    }
	    return -1;
	} 
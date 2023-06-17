int count(int arr[], int n, int x) {
	    // code here
	    int ans1=-1,ans2=-1;
    int lo=0,hi=n-1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(arr[mid]==x){
            ans1=mid;
            lo=mid+1;
        }
        else if(arr[mid]<x) lo = mid+1;
        else hi=mid-1;
    }
    lo=0,hi=n-1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(arr[mid]==x){
            ans2=mid;
            hi=mid-1;
        }
        else if(arr[mid]>x) hi=mid-1;
        else lo=mid+1;
    }
    if(ans1==-1) return 0;
    return ans1-ans2+1;
	}
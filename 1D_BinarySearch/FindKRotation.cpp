int findKRotation(int A[], int n) {
	    // code here
	    int ans=0;
        int h=n-1,l=0;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(A[mid]>A[n-1]){
                l = mid+1;
            }
            else{
                ans=mid;
                h = mid-1;
            }
        }
        return ans;
	}
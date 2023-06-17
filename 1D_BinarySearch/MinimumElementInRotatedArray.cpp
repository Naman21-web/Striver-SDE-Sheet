int findMin(int arr[], int n){
        //complete the function here
        int ans=0;
        int lo=0,hi=n-1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(arr[mid]<=arr[n-1]){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return arr[ans];
    }
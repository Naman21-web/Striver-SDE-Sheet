int findOnce(int arr[], int n)
    {
        //code here.
        int ans=n-1;
        int lo=0,hi=n-1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(((mid%2==0) && mid!=n-1 && arr[mid]!=arr[mid+1]) || ((mid%2 != 0) && mid!=0 && arr[mid]!=arr[mid-1])){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return arr[ans];
    }
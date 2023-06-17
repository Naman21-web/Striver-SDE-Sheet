int binarysearch(int arr[], int n, int k) {
        // code here
        int lo=0,hi=n-1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(arr[mid]<k){
                lo=mid+1;
            }
            else if(arr[mid]==k) return mid;
            else hi=mid-1;
        }
        return -1;
    }
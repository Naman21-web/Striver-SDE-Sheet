int searchInsertK(vector<int>Arr, int N, int k)
    {
        // code here
        int ans=N;
        int lo=0,hi=N-1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(Arr[mid]>=k){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
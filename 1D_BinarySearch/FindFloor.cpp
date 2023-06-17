int findFloor(vector<long long> v, long long n, long long x){
        
        // Your code here
        int ans=-1;
        long long lo=0,hi=n-1;
        while(lo<=hi){
            long long mid = lo + (hi-lo)/2;
            if(v[mid]<=x){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return ans;
    }
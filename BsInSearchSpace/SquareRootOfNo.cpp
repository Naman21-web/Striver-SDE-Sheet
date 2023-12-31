long long int floorSqrt(long long int x) 
    {
        // Your code goes here  
        long long hi=x,lo=1;
        long long ans=0;
        while(lo<=hi){
            long long mid = lo + (hi-lo)/2;
            if((mid*mid)<=x){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return ans;
    }
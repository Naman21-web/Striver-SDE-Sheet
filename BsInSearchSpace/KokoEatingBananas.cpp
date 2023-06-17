bool check(vector<int>& piles,int H,int mid,int N){
        int ans=0;
        for(int i=0;i<N;i++){
            ans += piles[i]/mid;
            if(piles[i]%mid != 0) ans++;
        } 
        // cout<<mid<<ans<<" ";
        if(ans<=H) return true;
        return false;
    }
    int Solve(int N, vector<int>& piles, int H) {
        // Code here
        int lo=1,hi=*max_element(piles.begin(),piles.end());
        int ans=hi;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(check(piles,H,mid,N)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
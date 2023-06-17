int check(int mid,int K,vector<int> &nums,int n){
        int ans=0;
        for(int i=0;i<n;i++){
            ans += nums[i]/mid;
            if(nums[i]%mid != 0) ans++;
        }
        return (ans<=K);
    }
    int smallestDivisor(vector<int>& nums, int K) {

        // Write your code here.
        int n=nums.size();
        int lo=1,hi=*max_element(nums.begin(),nums.end());
        int ans=0;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(check(mid,K,nums,n)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
int longestOnes(int n, vector<int>& nums, int k) {
        // Code here
        int flips=0,ans=0;
        int start=0,end=0;
        while(start<n){
            if(nums[start]==1) start++;
            else{
                if(flips==k){
                    ans=max(ans,start-end);
                    while(nums[end]==1) end++;
                    end++;
                    start++;
                }
                else{
                    flips++;
                    start++;
                }
            }
        }
        return max(ans,start-end);
    }
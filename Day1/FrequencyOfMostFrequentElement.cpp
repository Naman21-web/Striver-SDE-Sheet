int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long windowsum=0,windowsize=0,res=0;
        int pos=0;
        for(int i=0;i<nums.size();i++){
            windowsum += nums[i];
            windowsize = i-pos+1;
            while((nums[i]*windowsize)-windowsum>k){
                windowsum -= nums[pos++];
                windowsize--;
            }
            res = max(res,windowsize);
        }
        return res;
    }
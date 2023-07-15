class Solution {
public:
    int subarray(vector<int>& nums, int k){
        int n=nums.size();
        if(k>n) return 0;
        int start=0,end=0;
        int cntdist=0,ans=0;
        unordered_map<int,int> mp;
        while(end<n){
            if(mp.find(nums[end])!=mp.end()){mp[nums[end]]++;}
            else {mp[nums[end]]=1;cntdist++;}
            while(cntdist==k){
                ans += n-end;
                if(mp[nums[start]]==1){
                    mp.erase(nums[start]);
                    cntdist--;
                }
                else mp[nums[start]]--;
                start++;
            }
            end++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarray(nums,k)-subarray(nums,k+1);
    }
};
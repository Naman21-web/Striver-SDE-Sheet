bool isBSTTraversal(vector<int>& nums) {
        // your code here
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1])return false;
        }
        return true;
    }
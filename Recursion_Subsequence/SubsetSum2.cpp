void subset(int i,int n,vector<int> &nums,vector<int> &res,vector<vector<int>> &ans){
        // if(i==n){
            ans.push_back(res);
            // return;
        // }
        for(int j=i;j<n;j++){
            if(i!=j && nums[j]==nums[j-1]) continue;
            res.push_back(nums[j]);
            subset(j+1,n,nums,res,ans);
            res.pop_back();
            // subset(j+1,n,nums,res,ans);
        }
    }
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        // Write your code here
        int n=nums.size();
        vector<int> res;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        subset(0,n,nums,res,ans);
        return ans;
    }
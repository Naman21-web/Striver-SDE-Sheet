class Solution {
public:
    int func(vector<int> &nums){
        int prev1 = nums[0];
        int prev2 = 0;
        for(int i=1;i<nums.size();i++){
            int take = prev2+nums[i];
            int notTake = prev1;
            int cur = max(take,notTake);
            prev2=prev1;
            prev1 = cur;
        }
        return prev1;
    } 
        int func1(vector<int> &nums,int j,int k){
        int prev1 = nums[j];
        int prev2 = 0;
        for(int i=j+1;i<k;i++){
            int take = prev2+nums[i];
            int notTake = prev1;
            int cur = max(take,notTake);
            prev2=prev1;
            prev1 = cur;
        }
        return prev1;
    }     
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        // vector<int> temp1,temp2;
        // for(int i=0;i<nums.size();i++){
        //     if(i!=0) temp1.push_back(nums[i]);
        //     if(i!=nums.size()-1) temp2.push_back(nums[i]);
        // }
        //return max(func1(temp2,),func(temp1));
        return max(func1(nums,0,n-1),func1(nums,1,n));
    }
};
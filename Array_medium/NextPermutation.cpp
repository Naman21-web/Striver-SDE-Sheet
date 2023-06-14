void nextPermutation(vector<int>& nums) {
        int x = *max_element(nums.begin(), nums.end());
        //int swapp=0;
        int breakpt=-1;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                breakpt = i-1;
                //swapp++;
                break;
            }
        }
        if(breakpt<0){
            reverse(nums.begin(), nums.end());
            return;
        }
        else{
            for(int i=nums.size()-1;i>0;i--){
                if(nums[i]>nums[breakpt]){
                    swap(nums[i],nums[breakpt]);
                    reverse(nums.begin()+breakpt+1,nums.end());
                    break;
                }
            }
        }
    }
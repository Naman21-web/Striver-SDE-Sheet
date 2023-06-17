//approach1 : my approach
int search(int A[], int l, int h, int key){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        
        //complete the function here
        int ans=0;
        int end=h,st=l;
        //Finding the index where array starts originally
        while(l<=h){
            int mid = l + (h-l)/2;
            if(A[mid]>A[end]){
                l = mid+1;
            }
            else{
                ans=mid;
                h = mid-1;
            }
        }
        // reducing the search space
        if(ans!=0 && key<=A[ans-1] && key>A[end]) l=st,h=ans-1;
        else l=ans,h=end;
        ans=-1;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(A[mid]>key){
                h = mid-1;
            }
            else if(A[mid]==key) return mid;
            else{
                l = mid+1;
            }
        }
        return ans;
    }

//approach 2 :Striver approach
    int search(vector<int>& nums, int target) {
        int lo=0;int hi=nums.size()-1;int mid;
        while(hi>=lo){
            mid = (lo+hi)/2;
            if(target==nums[mid]) return mid;
            if(nums[lo]<=nums[mid]){
                if(nums[lo]<=target && nums[mid]>=target) hi=mid-1;
                else lo=mid+1;
            }
            else{
                if(target>=nums[mid] && target<=nums[hi]) lo=mid+1;
                else hi=mid-1;
            }
        }
        return -1;
    }
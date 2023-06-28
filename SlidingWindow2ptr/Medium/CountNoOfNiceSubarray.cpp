int countSubarray(int n, vector<int>& nums, int k) {
        // Code here
        int start=0,end=0;
        int cntodd=0,cntsubarray=0;
        int lastst;
        while(start<n){
            if(nums[start]%2!=0) cntodd++;
            if(cntodd>k){
                int lastend=end;
                while(cntodd>k){
                    if(nums[end]%2!=0) cntodd--;
                    end++;
                }
                // cout<<lastend<<" "<<end<<" "<<lastst<<" "<<start;
                cntsubarray += (start-lastst)*(end-lastend);
            }
            if(cntodd==k && nums[start]%2!=0) lastst=start;
            start++;
        }
         if(cntodd>=k){
            int lastend=end;
            while(cntodd>=k){
                if(nums[end]%2!=0) cntodd--;
                end++;
            }
            // cout<<lastend<<" "<<end<<" "<<lastst<<" "<<start;
            cntsubarray += (start-lastst)*(end-lastend);
        }
        return cntsubarray;
        // unordered_map<int,int> mp;
        // // mp[0]=1;
        // for(int i=0;i<n;i++){
        //     if(nums[i]%2!=0) cntodd++;
        //     if(mp[cntodd-k]) cntsubarray += mp[cntodd-k];
        //     mp[cntodd]++;
        // }
        // cntsubarray += mp[cntodd-k];
        // return cntsubarray;
    }
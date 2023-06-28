int longestKSubstr(string s, int k) {
        int n=s.size();
        vector<int> mp(123,0);
        //cnt stores no of distinct character present in window
        //start stores start of window and i is the end of window
        //ans is the final result which is the max length substring
        int cnt=0,start=0,ans=-1;
        for(int i=0;i<n;i++){
            if(mp[s[i]]==0){
                //If getting a new distinct character increase cnt
                cnt++;
            }
            //increase the no of times we get this character
            mp[s[i]]++;
            while(cnt>k){
                //if cnt is greater than k we have to remove one distinct character
                mp[s[start]]--;
                if(mp[s[start]]==0){
                    //So when start becomes zero that means 1 distinct character is removed
                    //so decrease cnt
                    cnt--;
                }
                start++;
            }
            //If distinct character is exactly k consider current sliding window in ans
            if(cnt==k) ans=max(ans,i-start+1);
        }
        return ans;
    }
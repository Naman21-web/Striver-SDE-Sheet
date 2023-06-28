int longestUniqueSubsttr(string S){
        //code
        int n=S.size(),ans=0,j=0;
        // unordered_map<char,int> mp;
        vector<int> mp(256,-1);
        for(int i=0;i<S.size();i++){
            if(mp[S[i]]>=j){
                ans = max(ans,i-j);
                j=mp[S[i]]+1;
            }
            // cout<<ans<<" ";
            mp[S[i]]=i;
        }
        return max(ans,n-j);
    }
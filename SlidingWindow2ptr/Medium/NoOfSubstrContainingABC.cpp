int countSubstring(string s) {
        // Code here
        int n=s.size();
        vector<int> mp(100,0);
        int start=0,ans=0,cnt=0;
        for(int end=0;end<n;end++){
            if(mp[s[end]]==0) cnt++;
            mp[s[end]]++;
            while(cnt==3){
                ans += (n-end);
                mp[s[start]]--;
                if(mp[s[start]]==0) cnt--;
                start++;
            }
        }
        return ans;
    }
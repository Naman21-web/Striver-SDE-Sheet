int maxDepth(string s) {
        // code here
        int cnt=0,ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') cnt++;
            else if(s[i]==')') cnt--;
            ans=max(ans,cnt);
        }
        return ans;
    }
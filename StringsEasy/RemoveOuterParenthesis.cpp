string removeOuter(string& s) {
        // code here
        string ans;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') {
                cnt++;
                if(cnt!=1) ans += s[i]; 
            }
            else {
                cnt--;
                if(cnt!=0) ans += s[i];
            }
            // if(cnt)
        }
        return ans;
    }
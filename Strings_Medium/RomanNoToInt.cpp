int romanToDecimal(string &str) {
        // code here
        unordered_map<char,int> mp;
        mp = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int ans=0,n=str.size();
        ans += mp[str[n-1]];
        for(int i=n-2;i>=0;i--){
            if(mp[str[i+1]]>mp[str[i]]) ans -= mp[str[i]];
            else ans += mp[str[i]];
        }
        return ans;
    }
bool check(int i,int n,string &s,string &ans,unordered_map<string,int> &mp){
        if(i==n){
            if(mp.find(ans)!=mp.end()) return true;
            return false;
        }
        bool res= false;
        ans += s[i];
        if(mp.find(ans)!=mp.end()){
            string v=ans;
            ans="";
            res = res || check(i+1,n,s,ans,mp);
            ans=v;
        }
        if(res==true) return true;
        res = res || check(i+1,n,s,ans,mp);
        return res;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        unordered_map<string,int> mp;
        mp[""]++;
        for(int i=0;i<wordDict.size();i++){
            mp[wordDict[i]]++;
        }
        string ans;
        return check(0,n,s,ans,mp);
    }
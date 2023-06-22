void substrings(int n,string &s,int prev,vector<string> &ans){
        if(n==0) {ans.push_back(s);return;}
        if(prev==0){
            s += '1';
            substrings(n-1,s,1,ans);
            s.pop_back();
        }
        s += '0';
        substrings(n-1,s,0,ans);
        s.pop_back();
    }

    vector<string> generate(int n){
        vector<string> ans;
        string s = "0";
        substrings(n-1,s,0,ans);
        s.pop_back();
        s += "1";
        substrings(n-1,s,1,ans);
        s.pop_back();
        return ans;
    }
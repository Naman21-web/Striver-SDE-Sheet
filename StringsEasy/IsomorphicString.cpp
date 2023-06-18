string generatePattern(string str){
        unordered_map<char,char> mp;
        string s;
        char cnt='1';
        for(int i=0;i<str.size();i++){
            if(mp.find(str[i])==mp.end()){
                mp[str[i]]=cnt;
                cnt++;
            }
            s += mp[str[i]];
        }
        return s;
    }
    bool areIsomorphic(string str1, string str2)
    {
        // Your code here
        if(str1.size()!=str2.size()) return 0;
        string s1=generatePattern(str1);
        string s2=generatePattern(str2);
        return (s1==s2);
    }
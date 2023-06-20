bool areRotations(string s1,string s2)
    {
        if(s1==s2) return true;
        string s=s1;
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        for(int i=0;i<s.size();i++){
            s1.pop_back();
            s1 = s[i] + s1;
            if(s1==s2) return true;
        }
        return false;
    }
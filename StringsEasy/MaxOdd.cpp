string maxOdd(string s) {
        // your code here
        string ans;
        int index=-1;
        for(int i=s.size()-1;i>=0;i--){
            if((s[i]-'0')%2!=0){
                index=i;
                break;
            }
        }
        for(int i=0;i<=index;i++) ans += s[i];
        return ans;
    }
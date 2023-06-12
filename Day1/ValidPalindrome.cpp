bool Palind(string s){
        int i=0,j=s.size()-1;
        while(i<=j){
            if(s[i]==s[j]){
                i++;j--;
            }
            else return false;
        }
        return true;
    }
    bool isPalindrome(string s) {
        string ans;
        for(int i=0;i<s.size();i++){
            if(s[i]>='A' && s[i]<='Z'){
                ans += s[i] - 'A' + 'a'; 
            }
            else if(s[i]>='a' && s[i]<='z') ans += s[i];
            else if(s[i]>='0' && s[i]<='9') ans += s[i];
        }
        cout<<ans<<" ";
        return Palind(ans);
    }
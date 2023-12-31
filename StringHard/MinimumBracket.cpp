class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt=0,ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') cnt++;
            else if(s[i]==')'){
                if(cnt>0) cnt--;
                else ans++;
            }
        }
        return ans+cnt;
    }
};
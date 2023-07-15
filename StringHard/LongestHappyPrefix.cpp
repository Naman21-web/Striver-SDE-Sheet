class Solution {
public:
//USING LPS ARRAY
    string longestPrefix(string s) {
        int n=s.size();
        vector<int> lps(n);
        lps[0]=0;
        int len=0,i=1;
        while(i<n){
            if(s[len]==s[i]){
                len++;
                lps[i]=len;
                i++;
            }
            else if(i<n && s[i]!=s[len]){
                if(len==0){
                    lps[i]=0;
                    i++;
                }
                else{
                    len = lps[len-1];
                }
            }
        }
        string ans="";
        for(int i=0;i<lps[n-1];i++) ans += s[i];
        return ans;
    }
};
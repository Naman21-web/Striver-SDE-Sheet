class Solution {
public:
    string countAndSay(int n) {
        if(n==0 || n==1) return "1";
        if(n==2) return "11";
        string previous="11";
        for(int i=3;i<=n;i++){
            string s;
            int cnt=1;
            char prev=previous[0];
            for(int j=1;j<previous.size();j++){
                char cur=previous[j];
                if(cur!=prev){
                    s += to_string(cnt);
                    s += prev;
                    prev=cur;
                    cnt=1;
                }
                else{
                    cnt++;
                }
            }
            s += to_string(cnt);
            s += prev;
            previous=s;
        }
        return previous;
    }
};
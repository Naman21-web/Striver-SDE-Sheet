string preToInfix(string s) {
        // Write your code here
        stack<string> st;
        string res;
        int n=s.size();
        string ans;
        for(int i=n-1;i>=0;i--){
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || ((s[i]-'0'>=0) && (s[i]-'0')<=9)){
                string ans;
                ans += s[i];
                st.push(ans);
            }
            else{
                string s1 = st.top();
                st.pop();
                string s2 = st.top();
                st.pop();
                string ans;
                ans += '(';
                ans += s1;
                ans += s[i];
                ans += s2;
                ans += ')';
                st.push(ans);
            }
        }
        res = st.top();
        return res;
    }
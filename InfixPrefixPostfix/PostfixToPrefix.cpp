string postToPre(string s) {
        // Write your code here
        stack<string> st;
        for(int i=0;i<s.size();i++){
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || ((s[i]-'0')>=0) && (s[i]-'0'<10)){
                string ans;
                ans += s[i];
                st.push(ans);
            }
            else{
                string s1=st.top();
                st.pop();
                string s2=st.top();
                st.pop();
                st.push(s[i]+s2+s1);
            }
        }
        return st.top();
    }
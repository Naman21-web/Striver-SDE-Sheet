nt check(char ch){
        if(ch=='^' || ch=='*' || ch=='/' || ch=='+' || ch=='-') return 1;
        return 0;
    }
    string preToPost(string s) {
        string ans;
        stack<string> st;
        int i=s.size()-1;
        for(i;i>=0;i--){
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || ((s[i]-'0')>=0) && (s[i]-'0'<10)){
                string res;
                res += s[i];
                st.push(res);
            }
            else{
                string res;
                string s1= st.top();
                st.pop();
                string s2=st.top();
                st.pop();
                st.push(s1+s2+s[i]);
            }
        }
        return st.top();
    }
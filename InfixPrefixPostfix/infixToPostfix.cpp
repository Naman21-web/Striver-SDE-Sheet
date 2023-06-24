int check(char ch){
        if(ch=='^') return 3;
        if(ch=='*' || ch=='/') return 2;
        return 1;
    }
    string infixToPostfix(string s) {
        // Your code here
        stack<char> st;
        string ans;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') st.push(s[i]);
            else if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || ((s[i]-'0'>=0) && (s[i]-'0')<=9)) ans += s[i];
            else if(s[i]==')'){
                while(st.top()!='('){
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                int x = check(s[i]);
                while(!st.empty() && st.top()!='('){
                    int y = check(st.top());
                    if(y>=x){
                        // cout<<ans<<" ";
                        ans += st.top();
                        st.pop();
                    }
                    else break;
                }
                st.push(s[i]);
            }
        }
        while(!st.empty()){ ans += st.top(); st.pop();}
        return ans;
    }
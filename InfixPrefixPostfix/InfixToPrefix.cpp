int check(char ch){
    if(ch=='^') return 3;
    else if(ch=='*' || ch=='/') return 2;
    else if(ch=='+' || ch=='-') return 1;
    return -1;
}
string infixToPrefix(string s){
    stack<char> st;
    string ans;
    reverse(s.begin(),s.end());
    for(int i=0;i<s.size();i++){
        if(s[i]=='(') s[i]=')';
        else if(s[i]==')') s[i]='(';
    }
    // cout<<s<<" ";
    for(int i=0;i<s.size();i++){
        if(s[i]=='(') st.push(s[i]);
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='(') {ans += st.top();st.pop();}
            st.pop();
        }
        else if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || ((s[i]-'0')>=0) && (s[i]-'0'<10)){
            ans += s[i];
        }
        else{
            int x = check(s[i]);
            while(!st.empty() && x<=check(st.top())){
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
string reverseWords(string S) 
    { 
        // code here 
        string ans;
        stack<string> st;
        string v;
        for(int i=0;i<S.size();i++){
            if(S[i]=='.'){
                st.push(v);
                v.clear();
            }
            else v += S[i];
        }
        st.push(v);
        while(!st.empty()){
            ans += st.top();
            st.pop();
            ans += '.';
        }
        ans.pop_back();
        return ans;
    } 
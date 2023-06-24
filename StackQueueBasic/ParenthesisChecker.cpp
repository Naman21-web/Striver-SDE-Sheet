char ismatch(char ch){
        if(ch=='}') return '{';
        else if(ch==')') return '(';
        else return '[';
    }
    bool ispar(string x)
    {
        // Your code here
        stack<char> st;
        for(int i=0;i<x.size();i++){
            if(x[i]=='(' || x[i]=='{' || x[i]=='[') st.push(x[i]);
            else{
                if(st.empty()) return false;
                if(ismatch(x[i])!=st.top()) return false;
                st.pop();
            }
        }
        if(!st.empty()) return false;
        return true;
    }
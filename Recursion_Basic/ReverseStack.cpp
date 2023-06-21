void iab(stack<int> &st,int no){
        if(st.empty()){
            st.push(no);
            return;
        }
        int x = st.top();
        st.pop();
        iab(st,no);
        st.push(x);
    }
    void Reverse(stack<int> &st){
        if(st.size()==1) return;
        int x=st.top();
        st.pop();
        Reverse(st);
        iab(st,x);
    }
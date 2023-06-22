void insert(stack<int> &st,int x){
    if(st.empty() || st.top()<=x) {st.push(x);return;}
    int y=st.top();
    st.pop();
    insert(st,x);
    st.push(y);
}
void SortedStack :: sort()
{
   //Your code here
   if(s.size()==1) return;
   int x=s.top();
    s.pop();
    sort();
    insert(s,x);
}
vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       vector<int> ans;
       stack<int> st;
       for(int i=0;i<n;i++){
           while(!st.empty() && price[i]>=price[st.top()]) st.pop();
           if(st.empty()) ans.push_back(i+1);
           else ans.push_back(i-st.top());
           st.push(i);
       }
       return ans;
    }
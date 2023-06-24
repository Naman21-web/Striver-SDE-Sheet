vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        stack<long long> st;
        vector<long long> ans;
        ans.push_back(-1);
        st.push(arr[n-1]);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && arr[i]>=st.top()) st.pop();
            if(st.empty()) ans.push_back(-1);
            else ans.push_back(st.top());
            st.push(arr[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
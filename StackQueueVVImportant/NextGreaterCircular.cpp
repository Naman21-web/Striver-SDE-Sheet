vector<int> nextGreaterElement(int N, vector<int>& arr) {
        // code here
        vector<int> ans;
        stack<int> st;
        for(int i=2*N-1;i>=0;i--){
            while(!st.empty() && st.top()<=arr[i%N]) st.pop();
            if(i<N){
                if(st.empty()) ans.push_back(-1);
                else ans.push_back(st.top());
            }
            st.push(arr[i%N]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
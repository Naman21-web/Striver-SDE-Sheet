long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        long long maxA=0;
        stack<int> st;
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || arr[st.top()]>=arr[i])){
                long long h = arr[st.top()];
                st.pop();
                int w;
                if(!st.empty()) w = i-st.top()-1;
                else w=i;
                maxA = max(maxA,h*w);
            }
            st.push(i);
        }
        return maxA;
    }
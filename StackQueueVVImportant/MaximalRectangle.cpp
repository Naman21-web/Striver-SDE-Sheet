int maxArea(vector<int> &dp,int n){
        int maxi=0;
        stack<int> st;
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || dp[st.top()]>=dp[i])){
                int h=dp[st.top()];
                st.pop();
                int w;
                if(!st.empty()) w = i-st.top()-1;
                else w=i;
                maxi = max(maxi,h*w);
                // cout<<maxi<<" ";
            }
            st.push(i);
        }
        return maxi;
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int maxi=0;
        vector<int> dp(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]==0) dp[j]=0;
                else dp[j]++;
            }   
            // for(int i=0;i<m;i++) cout<<dp[i]<<" ";
            // cout<<endl;
            maxi=max(maxi,maxArea(dp,m));
            // cout<<maxi<<" ";
            // cout<<endl;
        }
        return maxi;
    }
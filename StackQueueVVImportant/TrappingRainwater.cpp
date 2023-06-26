long long trappingWater(int arr[], int n){
        // code here
        stack<pair<int,int>> st,st2;
        vector<int> ans;
        ans.push_back(-1);
        st.push({arr[0],0});
        for(int i=1;i<n;i++){
            while(!st.empty() && st.top().first<arr[i]) st.pop();
            if(st.empty()) ans.push_back(-1);
            else ans.push_back(st.top().second);
            st.push({arr[i],i});
        }
        // for(int i=0;i<n;i++) cout<<ans[i]<<" ";
        // reverse)(ans.beg)
        int res=0;
        st2.push({arr[n-1],n-1});
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && st.top().first<arr[i]) st.pop();
            if(!st.empty() && ans[i]!=-1){
                // cout<<st.top().second<<" ";
                res += (st.top().second-ans[i]-1)*(min(st.top().first,arr[ans[i]])-arr[i]);
                // cout<<res<<" ";
            }
            st.push({arr[i],i});
        }
        return res;
    }
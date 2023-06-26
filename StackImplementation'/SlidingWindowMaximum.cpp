vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        multiset<int,greater<int>> st;
        for(int i=0;i<k;i++) st.insert(arr[i]);
        vector<int> ans;
        ans.push_back(*st.begin());
        int i=0;
        for(int j=k;j<n;j++){
            int x=arr[i++];
            st.erase(st.lower_bound(x));
            st.insert(arr[j]);
            ans.push_back(*st.begin());
        }
        return ans;
    }
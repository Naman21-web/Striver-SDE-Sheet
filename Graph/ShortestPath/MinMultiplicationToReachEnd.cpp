 int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        if(start==end) return 0;
        int mod=1e5;
        queue<pair<int,int>> q;
        q.push({0,start});
        vector<int> dist(1e5,1e9);
        dist[start]=0;
        while(!q.empty()){
            int node=q.front().second;
            int distance=q.front().first;
            q.pop();
            // cout<<node<<" ";
            for(int i=0;i<arr.size();i++){
                int ans = (node*arr[i])%mod;
                // cout<<ans<<" ";
                if(ans==end) return 1+distance;
                if(dist[ans]>1+distance){
                    dist[ans]=1+distance;
                    q.push({1+distance,ans});
                }
            }
        }
        return -1;
    }
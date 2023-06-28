vector<int> kLargest(int arr[], int n, int k)
    {
        // code here
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans(k);
        int i=k-1;
        while(!pq.empty()){
            ans[i]=pq.top();
            pq.pop();
            i--;
        }
        return ans; 
    }
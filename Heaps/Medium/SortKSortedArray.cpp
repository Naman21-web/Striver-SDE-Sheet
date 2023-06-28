vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[0].size();j++){
                pq.push(arr[i][j]);
            }
        }
        
        vector<int> ans;
        while(!pq.empty()){
            int x = pq.top();
            pq.pop();
            ans.push_back(x);
        }
        return ans;
    }
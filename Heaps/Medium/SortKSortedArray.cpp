vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        // priority_queue<int,vector<int>,greater<int>> pq;
        // for(int i=0;i<arr.size();i++){
        //     for(int j=0;j<arr[0].size();j++){
        //         pq.push(arr[i][j]);
        //     }
        // }
        
        // vector<int> ans;
        // while(!pq.empty()){
        //     int x = pq.top();
        //     pq.pop();
        //     ans.push_back(x);
        // }
        // return ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int n=arr.size();
        for(int i=0;i<n;i++){
            pq.push({arr[i][0],i});
        }
        vector<int> indexofarray(n,0),ans;
        while(!pq.empty()){
            auto topele=pq.top();
            pq.pop();
            ans.push_back(topele.first);
            int arrno=topele.second;
            if(indexofarray[arrno]+1!=arr[arrno].size()){
                pq.push({arr[arrno][indexofarray[arrno]+1],arrno});
                indexofarray[arrno]++;
            }
        }
        return ans;
    }
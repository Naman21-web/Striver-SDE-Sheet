vector<int> topK(vector<int>& nums, int k) {
        // Code here
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto ele:mp){
            pq.push({ele.second,ele.first});
        }
        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
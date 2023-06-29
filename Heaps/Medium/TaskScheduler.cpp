int leastInterval(int N, int K, vector<char> &tasks) {
        // code here
        if(K==0) return N;
        int maxi=0;
        unordered_map<char,int> mp;
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
            if(mp[tasks[i]]>maxi){
                maxi=mp[tasks[i]];
            }
        }
        int slot=maxi-1;
        int idle = slot*(K+1);
        for(auto ele:mp){
            idle -= min(slot,ele.second);
        }
        return N+max(0,idle);
    }
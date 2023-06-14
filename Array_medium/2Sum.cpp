vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        // Your code goes here 
        unordered_map<int,int> mp;
        vector<pair<int,int>> ans;
        for(int i=0;i<N;i++){
            mp[A[i]]++;
        }
        for(int j=0;j<M;j++){
            int rem = X-B[j];
            if(mp.find(rem)!=mp.end()){
                int x = mp[rem];
                while(x--){
                    ans.push_back({rem,B[j]});
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
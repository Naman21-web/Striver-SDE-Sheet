vector<int> sieveOfEratosthenes(int N)
    {
        // Write Your Code here
        vector<int> vis(N+1,0);
        vis[0]=1,vis[1]=1;
        vector<int> ans;
        for(int i=2;i*i<=N;i++){
            if(!vis[i]){
                // ans.push_back(i);
                for(int j=i*i;j<=N;j+=i){
                    vis[j]=1;
                }
            }
        }
        for(int i=2;i<=N;i++){
            if(!vis[i])ans.push_back(i);
        }
        return ans;
    }
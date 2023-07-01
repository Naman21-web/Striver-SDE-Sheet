vector<int> minPartition(int N)
    {
        // code here
        vector<int> ans;
        vector<int> coins = {1,2,5,10,20,50,100,200,500,2000};
        int j=9;
        while(N){
            while(coins[j]>N) j--;
            while(N>=coins[j]){
                N -= coins[j];
                ans.push_back(coins[j]);
            }
        }
        return ans;
    }
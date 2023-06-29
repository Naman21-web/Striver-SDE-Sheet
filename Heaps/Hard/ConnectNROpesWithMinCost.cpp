// int solve(int i,int price[],int n,int rod){
    //     if(i==n) return 0;
    //     int take=0;
    //     if(rod>=(i+1)) take = price[i]+solve(i,price,n,rod-i-1);
    //     int notTake = solve(i+1,price,n,rod);
    //     return max(take,notTake);
    // }
    
    // int solvememo(int i,int price[],int n,int rod,vector<vector<int>> &dp){
    //     if(i==n) return 0;
    //     if(dp[i][rod]!=-1) return dp[i][rod];
    //     int take=0;
    //     if(rod>=(i+1)) take = price[i]+solvememo(i,price,n,rod-i-1,dp);
    //     int notTake = solvememo(i+1,price,n,rod,dp);
    //     return dp[i][rod]=max(take,notTake);
    // }
    
    // int solvetabulation(int price[],int n,vector<vector<int>> &dp){
    //     for(int i=n-1;i>=0;i--){
    //         for(int rod=0;rod<=n;rod++){
    //             int take=0;
    //             if(rod>=(i+1)) take = price[i]+dp[i][rod-i-1];
    //             int notTake = dp[i+1][rod];
    //             dp[i][rod]=max(take,notTake);
    //         }
    //     }
    //     return dp[0][n];
    // }
    
    int solvetabulationopt(int price[],int n){
        vector<int> curr(n+1,0),next(n+1,0);
        for(int i=n-1;i>=0;i--){
            for(int rod=0;rod<=n;rod++){
                int take=0;
                if(rod>=(i+1)) take = price[i]+curr[rod-i-1];
                int notTake = next[rod];
                curr[rod]=max(take,notTake);
            }
            next=curr;
        }
        return next[n];
    }
    
    int cutRod(int price[], int n) {
        //code here
        // int ans=0;
        // for(int i=0;i<n;i++){
        //     int mult=1;
        //     while(mult*(i+1)<=n){
        //         int currprice = (mult*price[i]);
        //         int rem = n-(mult*(i+1));
        //         if(rem>0) currprice += price[rem-1];
        //         ans = max(ans,currprice);
        //         mult++;
        //     }
        // }
        // return ans;
        
        // vector<vector<int>> dp(n,vector<int> (n+1,-1));
        // return solvememo(0,price,n,n,dp);
        
        // vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        // return solvetabulation(price,n,dp);
        
        return solvetabulationopt(price,n);
    }
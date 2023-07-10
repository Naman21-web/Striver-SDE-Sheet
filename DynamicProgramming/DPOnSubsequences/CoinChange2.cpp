// #include<vector>
// long countways(int i,int *denominations, int n, int value){
//     if(value==0) return 1;
//     if(i==n) return 0; 
//     long take=0;
//     if(value>=denominations[i]) take = countways(i,denominations,n,value-denominations[i]);
//     long notTake = countways(i+1,denominations,n,value);
//     return take+notTake;
// }

long countways(int i,int *denominations, int n, int value,vector<vector<long>> dp){
    if(value==0) return 1;
    if(i==n) return 0; 
    if(dp[i][value]!=-1) return dp[i][value];
    long take=0; 
    if(value>=denominations[i]) take = countways(i,denominations,n,value-denominations[i],dp);
    long notTake = countways(i+1,denominations,n,value,dp);
    return dp[i][value]=take+notTake;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    vector<vector<long>> dp(n,vector<int> (value+1,-1));
    // long dp[n][value+1] = {-1};
    return countways(0,denominations,n,value,dp);
}
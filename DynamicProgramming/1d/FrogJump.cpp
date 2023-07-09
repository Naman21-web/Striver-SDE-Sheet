#include <bits/stdc++.h> 
// int findminenergy(int i,int n,vector<int> &heights){
//     if(i==n-1) return 0;
//     // if(i==n) return
//     int onejump = abs(heights[i]-heights[i+1])+findminenergy(i+1,n,heights);
//     int twojump=INT_MAX;
//     if(i<n-2)twojump=abs(heights[i]-heights[i+2])+findminenergy(i+2, n, heights);
//     return min(onejump,twojump);
// }
// int findminenergy(int i,int n,vector<int> &heights,vector<int> &dp){
//     if(i==n-1) return 0;
//     // if(i==n) return
//     if(dp[i]!=-1) return dp[i];
//     int onejump = abs(heights[i]-heights[i+1])+findminenergy(i+1,n,heights,dp);
//     int twojump=INT_MAX;
//     if(i<n-2)twojump=abs(heights[i]-heights[i+2])+findminenergy(i+2, n, heights,dp);
//     return dp[i]=min(onejump,twojump);
// }
int findminenergy(int n,vector<int> &heights,vector<int> &dp){
    
    for(int i=n-2;i>=0;i--){
        int onejump = abs(heights[i]-heights[i+1])+dp[i+1];
        int twojump=INT_MAX;
        if(i<n-2)twojump=abs(heights[i]-heights[i+2])+dp[i+2];
        dp[i]=min(onejump,twojump);
    }
    return dp[0];
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    // vector<int> dp(n,-1);
    vector<int> dp(n,0);
    return findminenergy( n, heights,dp);
}
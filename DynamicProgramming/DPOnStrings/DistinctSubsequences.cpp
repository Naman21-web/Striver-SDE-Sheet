#include <bits/stdc++.h> 
int mod=1e9+7;
// int subseqcnt(int i,int j,string &t,string &s){
//     if(j==0) return 1;
//     if(i==0) return 0;
//     if(t[i-1]==s[j-1]) return subseqcnt(i-1,j-1,t,s)+subseqcnt(i-1,j,t,s);
//     return subseqcnt(i-1,j,t,s);
// }

// int subseqcnt(int i,int j,string &t,string &s,vector<vector<int>> &dp){
//     if(j==0) return 1;
//     if(i==0) return 0;
//     if(dp[i][j]!=-1) return dp[i][j];
//     if(t[i-1]==s[j-1]) return dp[i][j]=((subseqcnt(i-1,j-1,t,s,dp)%mod)+(subseqcnt(i-1,j,t,s,dp)%mod))%mod;
//     return dp[i][j]=subseqcnt(i-1,j,t,s,dp)%mod;
// }

// int subseqcnt(int n,int m,string &t,string &s,vector<vector<int>> &dp){
//     for(int i=0;i<n;i++) dp[i][0]=1;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
//             if(t[i-1]==s[j-1]) dp[i][j] = ((dp[i-1][j]%mod)+(dp[i-1][j-1]%mod))%mod;
//             else dp[i][j] = dp[i-1][j]%mod;
//         }
//     }
//     return dp[n][m]%mod;
// }

// int subseqcnt(int n,int m,string &t,string &s){
//     vector<int> prev(m+1,0),curr(m+1,0);
//     // for(int i=0;i<n;i++) prev[0]=1;
//     prev[0]=1;
//     for(int i=1;i<=n;i++){
//         curr[0]=1;
//         for(int j=1;j<=m;j++){
//             if(t[i-1]==s[j-1]) curr[j] = ((prev[j]%mod)+(prev[j-1]%mod))%mod;
//             else curr[j] = prev[j]%mod;
//         }
//         prev=curr;
//     }
//     return prev[m]%mod;
// }

int subseqcnt(int n,int m,string &t,string &s){
    vector<int> curr(m+1,0);
    // for(int i=0;i<n;i++) prev[0]=1;
    // prev[0]=1;
    curr[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            if(t[i-1]==s[j-1]) curr[j] = ((curr[j]%mod)+(curr[j-1]%mod))%mod;
            else curr[j] = curr[j]%mod;
        }
        // prev=curr;
    }
    return curr[m]%mod;
}

int subsequenceCounting(string &t, string &s, int lt, int ls) {
    // Write your code here.
    // vector<vector<int>> dp(lt+1,vector<int> (ls+1,0));
    return subseqcnt(lt,ls,t,s)%mod;
} 
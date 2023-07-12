#include <bits/stdc++.h> 
int mod=1e9+7;
// int solveexp(int i,int j,bool isTrue,string &s){
//     if(i>j) return 0;
//     if(i==j){
//         if(isTrue) return (s[i]=='T');
//         else return (s[i]=='F');
//     }
//     int ways=0;
//     for(int ind=i+1;ind<=j-1;ind+=2){
//         int lt = solveexp(i,ind-1,true,s);
//         int lf = solveexp(i,ind-1,false,s);
//         int rt = solveexp(ind+1,j,true,s);
//         int rf = solveexp(ind+1,j,false,s);
//         if(s[ind]=='&'){
//             if(isTrue) ways += (lt*rt);
//             else ways += (lt*rf) +( lf*rt) +( lf*rf);
//         }
//         else if(s[ind]=='^'){
//             if(isTrue) ways += (lt*rf) + (lf*rt);
//             else ways += (lf*rf) + (lt*rt);
//         }
//         else{
//             if(isTrue) ways += (lt*rt) + (lf*rt) + (rf*lt);
//             else ways += (lf*rf);
//         }
//     }
//     return ways;
// }

// int solveexpmemo(int i,int j,bool isTrue,string &s,vector<vector<vector<int>>> &dp){
//     if(i>j) return 0;
//     if(i==j){
//         if(isTrue) return (s[i]=='T');
//         else return (s[i]=='F');
//     }
//     if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];
//     int ways=0;
//     for(int ind=i+1;ind<=j-1;ind+=2){
//         int lt = solveexpmemo(i,ind-1,true,s,dp);
//         int lf = solveexpmemo(i,ind-1,false,s,dp);
//         int rt = solveexpmemo(ind+1,j,true,s,dp);
//         int rf = solveexpmemo(ind+1,j,false,s,dp);
//         if(s[ind]=='&'){
//             if(isTrue) ways += (lt*rt);
//             else ways += (lt*rf) +( lf*rt) +( lf*rf);
//         }
//         else if(s[ind]=='^'){
//             if(isTrue) ways += (lt*rf) + (lf*rt);
//             else ways += (lf*rf) + (lt*rt);
//         }
//         else{
//             if(isTrue) ways += (lt*rt) + (lf*rt) + (rf*lt);
//             else ways += (lf*rf);
//         }
//     }
//     return dp[i][j][isTrue]=ways;
// }

int solveexptab(int n,string &s,vector<vector<vector<int>>> &dp){
    for(int i=n-1;i>=0;i-=2){
        for(int j=0;j<n;j+=2){
            for(int isTrue=0;isTrue<2;isTrue++){
                if(i>j) continue;
                if(i==j){
                    if(isTrue) dp[i][j][isTrue] = (s[i]=='T');
                    else dp[i][j][isTrue] = (s[i]=='F');
                    continue;
                }
                int ways=0;
                for(int ind=i+1;ind<=j-1;ind+=2){
                    int lt = dp[i][ind-1][true];
                    int lf = dp[i][ind-1][false];
                    int rt = dp[ind+1][j][true];
                    int rf = dp[ind+1][j][false];
                    if(s[ind]=='&'){
                        if(isTrue) ways += (lt*rt)%mod;
                        else ways += (((lt*rf)%mod) +((( lf*rt)%mod) +( lf*rf)%mod)%mod)%mod;
                    }
                    else if(s[ind]=='^'){
                        if(isTrue) ways += (((lt*rf)%mod) + ((lf*rt)%mod))%mod;
                        else ways += (((lf*rf)%mod) + ((lt*rt)%mod))%mod;
                    } else {
                      if (isTrue)
                        ways += (((lt * rt)%mod) + (((lf * rt)%mod) + ((rf * lt)%mod)%mod))%mod;
                      else
                        ways += (lf * rf)%mod;
                    }
                }
                dp[i][j][isTrue] = ways%mod;
            }
        }
    }
    return dp[0][n-1][true]%mod;
}
int evaluateExp(string & exp) {
    // Write your code here.
    int n=exp.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (n+1,vector<int> (2,0)));
    return solveexptab(n,exp,dp);
}
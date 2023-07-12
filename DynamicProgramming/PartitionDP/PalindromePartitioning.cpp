#include <bits/stdc++.h>
bool isPalindrome(int i,int j,string &str){
    while(i<=j){
        if(str[i]!=str[j]) return false;
        i++;
        j--;
    }
    return true;
} 
// int partition(int i,int j,string &str){
//     if(i>j) return 0;
//     if(i==j) return 1;
//     int mini=1e9;
//     for(int k=i;k<=j;k++){
//         if(isPalindrome(i,k,str)){
//             mini = min(mini,1+partition(k+1,j,str));
//         }
//     }
//     return mini;
// }

// int partition(int i,int j,string &str,vector<vector<int>> &dp){
//     if(i>j) return 0;
//     if(i==j) return 1;
//     if(dp[i][j]!=-1) return dp[i][j];
//     int mini=1e9;
//     for(int k=i;k<=j;k++){
//         if(isPalindrome(i,k,str)){
//             mini = min(mini,1+partition(k+1,j,str,dp));
//         }
//     }
//     return dp[i][j]=mini;
// }

// int partitiontab(int n,string &str,vector<vector<int>> &dp){
//     for(int i=n-1;i>=0;i--){
//         for(int j=0;j<n;j++){
//             if(i>j) continue;
//             if(i==j) {dp[i][j]=1; continue;}
//             int mini=1e9;
//             for(int k=i;k<=j;k++){
//                 if(isPalindrome(i,k,str)){
//                     mini = min(mini,1+dp[k+1][j]);
//                 }
//             }
//             dp[i][j]=mini;
//         }
//     }
//     return dp[0][n-1];
// }

int partitiontab(int n,string &str,vector<int> &dp){
    for(int i=n-1;i>=0;i--){
            // if(i==n-1) {dp[i]=1; continue;}
            int mini=1e9;
            for(int k=i;k<n;k++){
                if(isPalindrome(i,k,str)){
                    mini = min(mini,1+dp[k+1]);
                }
            }
            dp[i]=mini;
        }
    return dp[0];
}

int palindromePartitioning(string str) {
    // Write your code here
    int n=str.size();
    // vector<vector<int>> dp(n+1,vector<int> (n+1,0));
    vector<int> dp(n+1,0);
    return partitiontab(n,str,dp)-1;
}

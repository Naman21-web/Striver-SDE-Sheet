class Solution {
public:
    // int lcs(int i,int j,string s1,string s2){
    //     if(i==0 || j==0) return 0;
    //     if(s1[i-1]==s2[j-1]) return 1+lcs(i-1,j-1,s1,s2);
    //     else return max(lcs(i,j-1,s1,s2),lcs(i-1,j,s1,s2));
    // }

    // int lcs(int i,int j,string s1,string s2,vector<vector<int>> &dp){
    //     if(i==0 || j==0) return 0;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     if(s1[i-1]==s2[j-1]) return dp[i][j]=1+lcs(i-1,j-1,s1,s2,dp);
    //     else return dp[i][j]=max(lcs(i,j-1,s1,s2,dp),lcs(i-1,j,s1,s2,dp));
    // }

    // int lcs(int n,int m,string s1,string s2,vector<vector<int>> &dp){
    //     for(int i=1;i<=n;i++){
    //         for(int j=1;j<=m;j++){
    //             if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
    //             else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
    //         }
    //     }
    //     return dp[n][m];
    // }

    int lcs(int n,int m,string s1,string s2){
        vector<int> prev(m+1,0),curr(m+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]) curr[j]=1+prev[j-1];
                else curr[j]=max(curr[j-1],prev[j]);
            }
            prev=curr;
        }
        return curr[m];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        // vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        // return lcs(n,m,text1,text2);
        // return lcs(n,m,text1,text2,dp);
        // return lcs(n,m,text1,text2,dp);
        return lcs(n,m,text1,text2);
    }
};
class Solution {
public:
    // int minOp(int i,int j,string &word1,string &word2){
    //     if(i<0) return j+1;
    //     if(j<0) return i+1;

    //     if(word1[i]==word2[j]) return minOp(i-1,j-1,word1,word2);
    //     return 1+min(minOp(i-1,j-1,word1,word2),min(minOp(i-1,j,word1,word2),minOp(i,j-1,word1,word2)));
    // }

    // int minOp(int i,int j,string &word1,string &word2,vector<vector<int>> &dp){
    //     if(i<0) return j+1;
    //     if(j<0) return i+1;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     if(word1[i]==word2[j]) return dp[i][j]=minOp(i-1,j-1,word1,word2,dp);
    //     return dp[i][j]=1+min(minOp(i-1,j-1,word1,word2,dp),min(minOp(i-1,j,word1,word2,dp),minOp(i,j-1,word1,word2,dp)));
    // }

    // int minOp(int n,int m,string &word1,string &word2,vector<vector<int>> &dp){
    //     for(int j=0;j<=m;j++) dp[0][j]=j;
    //     for(int i=0;i<=n;i++) dp[i][0]=i;

    //     for(int i=1;i<=n;i++){
    //         for(int j=1;j<=m;j++){
    //             if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
    //             else dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
    //         }
    //     }
    //     return dp[n][m];
    // }

    int minOp(int n,int m,string &word1,string &word2){
        vector<int> curr(m+1,0),prev(m+1,0);
        for(int j=0;j<=m;j++) prev[j]=j;

        for(int i=1;i<=n;i++){
            curr[0]=i;
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]) curr[j]=prev[j-1];
                else curr[j]=1+min(prev[j-1],min(prev[j],curr[j-1]));
            }
            prev=curr;
        }
        return prev[m];
    }
    int minDistance(string word1, string word2) {
        int n= word1.size();
        int m = word2.size();

        // return minOp(n-1,m-1,word1,word2);

        // vector<vector<int>> dp(n,vector<int> (m,-1));
        // return minOp(n-1,m-1,word1,word2,dp);

        // vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        // return minOp(n,m,word1,word2,dp);

        return minOp(n,m,word1,word2);
    }
};
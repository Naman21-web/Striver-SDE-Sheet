class Solution {
public:
    // bool match(int i,int j,string &s,string &p){
    //     if(i<0 && j<0) return true;
    //     if(i<0 && j>=0) return false;
    //     if(j<0){
    //         bool flag=true;
    //         for(int k=0;k<=i;k++){
    //             if(p[k] != '*'){
    //                 flag=false;
    //                 break;
    //             }
    //         }
    //         return flag;
    //     }

    //     if(p[i]==s[j] || p[i]=='?') return match(i-1,j-1,s,p);
    //     if(p[i]=='*') return match(i-1,j,s,p) || match(i,j-1,s,p);
    //     return false;
    // }

    // bool match(int i,int j,string &s,string &p,vector<vector<int>> &dp){
    //     if(i<0 && j<0) return true;
    //     if(i<0 && j>=0) return false;
    //     if(j<0){
    //         bool flag=true;
    //         for(int k=0;k<=i;k++){
    //             if(p[k] != '*'){
    //                 flag=false;
    //                 break;
    //             }
    //         }
    //         return flag;
    //     }

    //     if(dp[i][j] != -1) return dp[i][j];

    //     if(p[i]==s[j] || p[i]=='?') return dp[i][j]=match(i-1,j-1,s,p,dp);
    //     if(p[i]=='*') return dp[i][j]= match(i-1,j,s,p,dp) || match(i,j-1,s,p,dp);
    //     return dp[i][j]=false;
    // }

    // bool match(int n,int m,string &s,string &p,vector<vector<bool>> &dp){
    //     dp[0][0]=true;
    //     for(int j=1;j<=m;j++) dp[0][j]= false;
    //     for(int i=1;i<=n;i++){
    //         bool flag=true;
    //         for(int k=1;k<=i;k++){
    //             if(p[k-1] != '*'){
    //                 flag=false;
    //                 break;
    //             }
    //         }
    //         dp[i][0]= flag;
    //     }
    //     for(int i=1;i<=n;i++){
    //         for(int j=1;j<=m;j++){
    //             if(p[i-1]==s[j-1] || p[i-1]=='?')  dp[i][j]=dp[i-1][j-1];
    //             else if(p[i-1]=='*')  dp[i][j]= dp[i-1][j] || dp[i][j-1];
    //             else dp[i][j]=false;
    //         }
    //     }
    //     return dp[n][m];
    // }

    bool match(int n,int m,string &s,string &p){
        vector<bool>  prev(m+1,false),curr(m+1,false);
        prev[0]=true;
        for(int j=1;j<=m;j++) prev[j]= false;
        
        for(int i=1;i<=n;i++){
                bool flag=true;
                for(int k=1;k<=i;k++){
                    if(p[k-1] != '*'){
                        flag=false;
                        break;
                    }
                }
                curr[0]= flag;
            for(int j=1;j<=m;j++){
                if(p[i-1]==s[j-1] || p[i-1]=='?')  curr[j]=prev[j-1];
                else if(p[i-1]=='*')  curr[j]= prev[j] || curr[j-1];
                else curr[j]=false;
            }
            prev=curr;
        }
        return prev[m];
    }

    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        // return match(n-1,m-1,s,p);

        // vector<vector<int>> dp(n,vector<int> (m,-1));
        // return match(n-1,m-1,s,p,dp);

        // vector<vector<bool>> dp(n+1,vector<bool> (m+1,false));
        // return match(n,m,s,p,dp);

        return match(n,m,s,p);
    }
};
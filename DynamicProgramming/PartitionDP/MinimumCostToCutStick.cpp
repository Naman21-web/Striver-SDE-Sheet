class Solution {
public:
    // int findmincost(int i,int j,vector<int> &cuts){
    //     if(i>j) return 0;
    //     int mini=INT_MAX;
    //     for(int k=i;k<=j;k++){
    //         int cost = cuts[j+1]-cuts[i-1]+findmincost(i,k-1,cuts)+findmincost(k+1,j,cuts);
    //         mini = min(cost,mini);
    //     }
    //     return mini;
    // }
    // int findmincost(int i,int j,vector<int> &cuts,vector<vector<int>> &dp){
    //         if(i>j) return 0;
    //         if(dp[i][j]!=-1) return dp[i][j];
    //         int mini=INT_MAX;
    //         for(int k=i;k<=j;k++){
    //             int cost = cuts[j+1]-cuts[i-1]+findmincost(i,k-1,cuts,dp)+findmincost(k+1,j,cuts,dp);
    //             mini = min(cost,mini);
    //         }
    //         return dp[i][j]=mini;
    //     }

    int findmincost(int cutssize,vector<int> &cuts,vector<vector<int>> &dp){
            for(int i=cutssize;i>=1;i--){
                for(int j=1;j<=cutssize;j++){
                    if(i>j) continue;
                    int mini=INT_MAX;
                    for(int k=i;k<=j;k++){
                        int cost = cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j];
                        mini = min(cost,mini);
                    }
                    dp[i][j]=mini;
                }
            }
            
            return dp[1][cutssize];
        }

    int minCost(int n, vector<int>& cuts) {
        int cutssize=cuts.size();
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(cutssize+2,vector<int> (cutssize+2,0));
        return findmincost(cutssize,cuts,dp);
    }
};
#include <bits/stdc++.h> 
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
int canYouMake(string &str, string &ptr)
{
    // Write your code here.
    int n=str.size(),m=ptr.size();
    return n+m-(2*lcs(n,m,str,ptr));
}
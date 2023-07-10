#include <bits/stdc++.h> 
int lcs(string t,string s){
    int n=t.size();
    vector<int> prev(n+1,0),curr(n+1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(t[i-1]==s[j-1]) curr[j]=1+prev[j-1];
            else curr[j]=max(curr[j-1],prev[j]);
        }
        prev=curr;
    }
    return prev[n];
}
int longestPalindromeSubsequence(string s)
{
    // Write your code here.
    string t = s;
    reverse(s.begin(),s.end());
    return lcs(t,s);
}
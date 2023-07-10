#include <bits/stdc++.h> 
int lcs(int n,string &str1,string &str2){
    vector<int> curr(n+1,0),prev(n+1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(str1[i-1]==str2[j-1]) curr[j] = 1+prev[j-1];
            else curr[j] = max(curr[j-1],prev[j]);
        }
        prev=curr;
    }
    return prev[n];
}

int minInsertion(string &str)
{
    // Write your code here.
    int n=str.size();
    string rts = str;
    reverse(str.begin(),str.end());
    return n-lcs(n,rts,str);
}
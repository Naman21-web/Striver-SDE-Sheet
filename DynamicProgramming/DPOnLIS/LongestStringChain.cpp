#include <bits/stdc++.h> 
struct comp{
    bool operator()(const string &s1,string &s2){
        return s1.size()<s2.size();
    }
};
bool check(string s1,string s2){
    if(s1.size()!=1+s2.size()) return false;
    int i=0,j=0;
    while(i<s1.size() && j<s2.size()){
        if(s1[i]==s2[j]){i++;j++;}
        else i++;
    }
    if(i==s1.size() && j!=s2.size()) return false;
    return true;
}
int longestStrChain(vector<string> &arr)
{
    // Write your code here.
    int n=arr.size();
    sort(arr.begin(),arr.end(),comp());
    // for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    vector<int> dp(n,1);
    int ans=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            // cout<<check(arr[i],arr[j])<<" ";
            if(check(arr[i],arr[j]) && 1+dp[j]>dp[i]){
                dp[i]=1+dp[j];
            }
        }
        // cout<<endl;
        ans = max(ans,dp[i]);
    }
    return ans;
}
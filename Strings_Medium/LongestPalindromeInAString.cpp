void solve(int i,int j,int n,string S,string& ans){
        while(i>=0 && j<n){
            if(S[i]==S[j]){
                i--;
                j++;
            }
            else break;
        }
        i++,j--;
        int len = j-i+1;
        if(len>ans.size()){
            ans = S.substr(i,len);
        }
    }
    string longestPalin (string S) {
        // code here
        int n=S.size();
        string ans=S.substr(0,1);
        for(int i=1;i<n;i++){
            solve(i,i,n,S,ans);
            if(S[i]==S[i-1]) solve(i-1,i,n,S,ans);
        }
        return ans;
    }
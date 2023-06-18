 int beautySum(string s) {
        int n=s.size();
        int sum=0;
        
        for(int i=0;i<n;i++){
            // string v=s[i];
            unordered_map<char,int> mp;
            mp[s[i]]++;
            for(int j=i+1;j<n;j++){
                // string v = s.substr(i,j-i+1);
                // v += s[j];
                mp[s[j]]++;
                // for(int k=0;k<v.size();k++){
                //     mp[v[k]]++;
                // }
                int mini=INT_MAX,maxi=0;
                for(auto x:mp){
                    mini = min(x.second,mini);
                    maxi = max(x.second,maxi);
                }
                sum += maxi-mini;
            }
        }
        return sum;           
    }
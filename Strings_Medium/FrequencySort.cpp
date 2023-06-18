string frequencySort(string s) {
       unordered_map<char,int> mp;
       map<int,vector<char>,greater<int>> mp2;
       for(int i=0;i<s.size();i++){
           mp[s[i]]++;
       }
       for(auto x:mp){
           mp2[x.second].push_back(x.first);
       }
       string ans;
       for(auto x:mp2){
           for(auto y:x.second){
                int n=x.first;
                while(n--){
                    ans += y;
                }
           }
       }
       return ans;
    }
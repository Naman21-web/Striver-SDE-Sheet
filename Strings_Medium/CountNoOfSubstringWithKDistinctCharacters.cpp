long long int kdist(string s,int k){
        int n = s.size();
        int begin=0,end=0;
        long long int cnt=0;
        int size=0;
        vector<long long int> mp(26,0);
        while(end<n){
            if(mp[s[end]-'a']==0) size++;
            mp[s[end]-'a']++;
            end++;
            while(size>=k){
                mp[s[begin]-'a']--;
                if(mp[s[begin]-'a']==0){
                    size--;
                }
                cnt += s.length()-end+1;
                begin++;
                // cnt++;
            }
        }
        return cnt;
    }
    long long int substrCount (string s, int k) {
    	//code here.
    // 	cout<<kdist(s,k-1)<<kdist(s,k)<<kdist(s,k+1)<<endl;
    	return kdist(s,k)-kdist(s,k+1);
    }
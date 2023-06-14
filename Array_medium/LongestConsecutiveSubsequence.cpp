int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      unordered_map<int,int> mp;
      for(int i=0;i<N;i++){
          mp[arr[i]]++;
      }
      int ans=1;
      for(auto x:mp){
          if(mp.find(x.first-1)==mp.end()){
              int cnt=1;
              int y=x.first;
              while(mp.find(y+1)!=mp.end()){
                  y++;
                  cnt++;
              }
              ans = max(ans,cnt);
          }
      }
      return ans;
    }
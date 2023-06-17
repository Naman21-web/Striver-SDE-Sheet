int check(int mid,int M,int K,vector<int> &bloomDay,int n){
        int ans=0,cnt=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=mid) cnt++;
            else cnt=0;
            if(cnt==K){
                ans++;
                cnt=0;
            }
        }
        return (ans>=M);
    }
    int solve(int M, int K, vector<int> &bloomDay){
      // Code here
      int n=bloomDay.size();
      if(M*K > n) return -1;
      int ans=-1;
      int lo=*min_element(bloomDay.begin(),bloomDay.end());
      int hi=*max_element(bloomDay.begin(),bloomDay.end());
      while(lo<=hi){
          int mid= lo + (hi-lo)/2;
          if(check(mid,M,K,bloomDay,n)){
              ans=mid;
              hi=mid-1;
          }
          else lo=mid+1;
      }
      return ans;
    }
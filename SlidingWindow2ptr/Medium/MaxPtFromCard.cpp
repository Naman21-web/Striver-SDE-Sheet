long long maxScore(vector<int> &cardPoints, int n, int k) {
        // code here
        long long ans=0;
        vector<long long> pref(n);
        pref[0]=cardPoints[0];
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+cardPoints[i];
        }
        ans = pref[n-1]-pref[n-k-1];
        for(int i=0;i<k;i++){
            long long currsum = pref[i]+pref[n-1]-pref[n-k+i];
            ans = max(ans,currsum);
        }
        return ans;
    }
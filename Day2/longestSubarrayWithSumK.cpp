int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        map <int,int> mp;
        int sum = 0;
        int m = 0;
        for(int i = 0; i<N; i++){
            sum = sum + A[i];
            if(sum == K) m = max(m,i+1);
            if(mp.find(sum-K) != mp.end()){
                m = max(m, i-mp[sum-K]);
            }
            if(mp.find(sum)==mp.end()){
                mp[sum] = i;
            }
        }
        return m;
    } 
 long long reversedBits(long long X) {
        // code here
        int cnt=31;
        long long ans=0;
        while(X){
            if(X&1){
                ans += (pow(2,cnt));
            }
            cnt--;
            X = X>>1;
        }
        return ans;
    }
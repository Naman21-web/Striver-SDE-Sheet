long long gcm(long long a , long long b){
        if(a==0) return b;
        return gcm(b%a,a);
    }
    
    vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
        long long gcd= gcm(A,B);;
        long long lcm = A*B;
        lcm = lcm/gcd;
        vector<long long> ans(2);
        ans[0]=lcm;
        ans[1]=gcd;
        return ans;
    }
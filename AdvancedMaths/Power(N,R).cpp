long long power(int N,int R)
    {
       //Your code here
    //   int mod=1e9+7;
       if(R==0) return 1;
       long long p = power(N,R/2)%mod;
        if(R%2==0) return ((p%mod)*(p%mod))%mod;
        return ((N*(p%mod))%mod*(p%mod))%mod;
    }
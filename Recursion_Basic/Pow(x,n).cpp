long long powerrecurse(int N,int R){
        if(R==0) return 1;
        long long ans = powerrecurse(N,R/2);
        if(R%2!=0) return (((N*ans)%mod)*ans)%mod;
        else return (ans*ans)%mod;
    }
    long long power(int N,int R)
    {
       //Your code here
        return powerrecurse(N,R)%mod;
    }
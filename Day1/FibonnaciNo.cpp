int fib(int n) {
        if(n==0 || n==1) return n;
       vector<int> fibon(n+1);
       fibon[0]=0,fibon[1]=1;
       for(int i=2;i<=n;i++){
           fibon[i] = fibon[i-1]+fibon[i-2];
       }
       return fibon[n];
    }
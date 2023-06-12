long long sumOfDivisors(int N)
    {
        long long ans=0;
        // Write Your Code here
        for(int i=1;i<=N;i++){
            ans += i*(N/i);
        }
        return ans;
    }
void solve(int no,long long N,long long mul,vector<long long> &ans){
        if(mul*no<=N) ans.push_back(no*mul);
        else return;
        solve(no+1,N,mul*no,ans);
    }
    vector<long long> factorialNumbers(long long N)
    {
        // Write Your Code here
        vector<long long> ans;
        ans.push_back(1);
        solve(2,N,1,ans);
        return ans;
    }
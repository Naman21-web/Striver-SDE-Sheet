void print_divisors(int n) {
        // Code here.
        vector<int> ans;
        int x=sqrt(n);
        for(int i=1;i<=x;i++){
            if((n%i)==0) ans.push_back(i);
        }
        int a=ans.size();
        for(int i=0;i<a;i++) cout<<ans[i]<<" ";
        if(x*x==n) a--;
        for(int i=a-1;i>=0;i--) cout<<n/ans[i]<<" ";
    }
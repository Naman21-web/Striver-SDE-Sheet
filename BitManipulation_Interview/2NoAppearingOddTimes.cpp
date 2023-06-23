vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        long long int xora=0;
        for(int i=0;i<N;i++){
            xora = xora^Arr[i];
        }
        long long int x = xora&(~(xora-1));
        // cout<<x;
        long long int no=0;
        for(int i=0;i<N;i++){
            if(Arr[i]&x) no = no^Arr[i];
        }
        vector<long long int> ans= {no,no^xora};
        sort(ans.rbegin(),ans.rend());
        return ans;
    }
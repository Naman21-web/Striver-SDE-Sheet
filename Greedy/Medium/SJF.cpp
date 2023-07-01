int solve(vector<int>& bt) {
        // code here
        sort(bt.begin(),bt.end());
        int n = bt.size();
        int sum=0;
        int avg=0;
        for(int i=1;i<n;i++){
            sum += bt[i-1];
            avg += sum;
        }
        return avg/n;
    }
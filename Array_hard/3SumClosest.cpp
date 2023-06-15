int closest3Sum(int A[], int N, int X)
    {
        // code here
        sort(A,A+N);
        int diff=INT_MAX;
        int ans=X;
        for(int i=0;i<N;i++){
            int sum = X-A[i];
            int lo=i+1,hi=N-1;
            while(lo<hi){
                int lohi = A[lo]+A[hi];
                if(lohi<=sum){
                    int sub = sum-lohi;
                    if(sub==0) return X;
                    if(sub<=diff){
                        if(sub==diff)ans=max(ans,A[i]+lohi);
                        else ans=A[i]+lohi;
                        diff=sub;
                    }
                    lo++;
                }
                else{
                    int sub = lohi-sum;
                    if(sub==0) return X;
                    if(sub<=diff){
                        if(sub==diff)ans=max(ans,A[i]+lohi);
                        else ans=A[i]+lohi;
                        diff=sub;
                    }
                    hi--;
                }
            }
        }
        return ans;
    }
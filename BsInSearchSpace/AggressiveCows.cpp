int check(int mid,int n,int k,vector<int> &stalls){
        int ans=1,prev=0;
        for(int i=1;i<n;i++){
            if((stalls[i]-stalls[prev])>=mid){
                ans++;
                prev=i;
            }
        }
        return (ans>=k);
    }
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(),stalls.end());
        int lo=0,hi=1e9;
        int ans=0;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(check(mid,n,k,stalls)){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return ans;
    }
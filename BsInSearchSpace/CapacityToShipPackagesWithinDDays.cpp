int check(int mid,int N,int D,int arr[]){
        int ans=1,cap=0;
        for(int i=0;i<N;i++){
            if(arr[i]>mid) return false;
            cap += arr[i];
            if(cap>mid){
                cap=arr[i];
                ans++;
            }
        }
        return (ans<=D);
    }
    int leastWeightCapacity(int arr[], int N, int D) {
        // code here
         int lo=1,hi=accumulate(arr,arr+N,0);
        int ans=0;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(check(mid,N,D,arr)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
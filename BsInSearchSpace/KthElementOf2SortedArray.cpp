int check(int target,int arr[],int n){
        int lo=0,hi=n-1;
        int ans=-1;
        while(lo<=hi){
            int mid=lo + (hi-lo)/2;
            if(arr[mid]<=target){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        // cout<<ans<<" ";
        return ans+1;
    }
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int ans=0;
        int lo = min(arr1[0],arr2[0]);
        int hi=max(arr1[n-1],arr2[m-1]);
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            int cnt=0;
            cnt += check(mid,arr1,n);
            // cout<<cnt<<" ";
            cnt += check(mid,arr2,m);
            // cout<<mid<<" "<<cnt<<" ";
            if(cnt>=k){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
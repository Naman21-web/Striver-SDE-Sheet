long long conquer(long long arr[],long long lo,long long mid,long long hi){
        long long i=lo,j=mid+1,n=mid+1;
        vector<long long> temp;
        long long ans=0;
        while(i<mid+1 && j<hi+1){
            if(arr[j]<arr[i]){
                temp.push_back(arr[j]);
                ans += n-i;
                j++;
            }
            else{
                temp.push_back(arr[i]);
                i++;
            }
        }
        while(i<mid+1){
            temp.push_back(arr[i]);
            i++;
        }
        while(j<hi+1){
            temp.push_back(arr[j]);
            j++;
        }
        for(long long i=lo;i<=hi;i++){
            arr[i] = temp[i-lo];
        }
        return ans;
    }
    
    long long divide(long long arr[],long long lo,long long hi){
        long long ans=0;
        if(lo<hi){
            long long mid = lo + ((hi-lo)/2);
            ans += divide(arr,lo,mid);
            ans += divide(arr,mid+1,hi);
            ans += conquer(arr,lo,mid,hi);
        }
        return ans;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        // unordered_map<long long,int> mp;
        long long lo=0,hi=N-1;   
        return divide(arr,lo,hi);
    }

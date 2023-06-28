int numberOfSubarrays(vector<int>& arr, int n, int target){
        // code here
        int start=0,end=0;
        int sum=0,cnt=0;
        int lastend,lastst;
        while(start<n){
            sum += arr[start];
            if(sum>target){
                lastend=end;
                while(sum>target) {
                    sum -= arr[end++];
                }
                cnt += (end-lastend)*(start-lastst);
                // cout<<cnt<<" ";
            }
            if(arr[start]==1) lastst=start;
            start++;
        }
        // cout<<start<<end<<" ";
        if(sum==target){
            lastend=end;
            while(sum==target) {
                sum -= arr[end++];
            }
            cnt += (end-lastend)*(start-lastst);
        }
        return cnt;
    }
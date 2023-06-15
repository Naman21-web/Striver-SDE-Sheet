vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        vector<int> ans;
        int xora=0;
        for(int i=0;i<n;i++){
            xora ^= abs(arr[i]);
            arr[abs(arr[i])-1] *= -1;
            if(arr[abs(arr[i])-1]>0) ans.push_back(abs(arr[i]));
        }
        int totalxor;
        if(n%4==0) totalxor=n;
        if(n%4==1) totalxor=1;
        if(n%4==2) totalxor=n+1;
        if(n%4==3) totalxor=0;
        ans.push_back(totalxor^ans[0]^xora);
        return ans;
    }
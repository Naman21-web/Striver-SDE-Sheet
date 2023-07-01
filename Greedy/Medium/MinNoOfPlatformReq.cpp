//railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    // 	int ans=0;
    // // 	sort
    //     int mini = arr[0];
    //     int maxi = dep[0];
    //     int cnt=1;
    //     int prev=dep[0];
    //     for(int i=1;i<n;i++){
    //         if(arr[i]<maxi){
    //             if(arr[i]<prev)cnt++;
    //             maxi = max(dep[i],maxi);
    //             prev=dep[i];
    //         }
    //         else{
    //             prev = dep[i];
    //             ans=max(ans,cnt);
    //             cnt=1;
    //             mini=arr[i];
    //             maxi=dep[i];
    //         }
    //     }
    //     ans = max(ans,cnt);
       sort(arr,arr+n);
       sort(dep,dep+n);
        int j=0;
       int cnt=1;
       int ans=0;
       for(int i=1;i<n;i++){
           while(arr[i]>dep[j]) j++,cnt--;
            cnt++;
            ans=max(ans,cnt);
       }
       return ans;
    }
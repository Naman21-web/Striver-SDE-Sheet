int searchInSorted(int arr[], int N, int K) 
    { 
    
       // Your code here
       int lo=0,hi=N-1;
       while(lo<=hi){
           int mid = lo+ (hi-lo)/2;
           if(arr[mid]==K) return 1;
           else if(arr[mid]<K) lo=mid+1;
           else hi=mid-1;
       }
       return -1;
    }
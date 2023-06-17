pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    sort(arr,arr+n);
    int ans1=-1,ans2=-1;
    int lo=0,hi=n-1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(arr[mid]<x){
            ans1=arr[mid];
            lo=mid+1;
        }
        else if(arr[mid]>x){
            ans2=arr[mid];
            hi=mid-1;
        }
        else{
            ans1=arr[mid];
            ans2=arr[mid];
            break;
        }
    }
    return {ans1,ans2};
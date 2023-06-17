int KthMissingElement(int a[], int n, int k)
{
    // Complete the function
    int ans=0;
    // if(a[0]!=1) ans += a[0]-1;
    // cout<<ans;
    // if(k<=ans) return k;
    for(int i=1;i<n;i++){
        int diff=a[i]-a[i-1]-1;
        // cout<<diff<<" "<<ans<<" ";
        if(diff==0) continue;
        else if((diff+ans)>=k){
            return a[i-1]+k-ans;
        }
        else ans += diff;
        // cout<<ans<<" ";
    }
    return -1;
}
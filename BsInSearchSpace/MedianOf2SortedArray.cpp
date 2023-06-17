double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // vector<int> v;
        int n=nums1.size(),m=nums2.size();
        if(m<n) return findMedianSortedArrays(nums2,nums1);
        int mid = (n+m+1)/2;
        int lo=0,hi=n;
        while(lo<=hi){
            int cnt1 = lo + (hi-lo)/2;
            int cnt2 = mid-cnt1;
            int l1=INT_MIN,l2=INT_MIN,r1=INT_MAX,r2=INT_MAX;
            if(cnt1!=0) l1=nums1[cnt1-1];
            if(cnt1!=n) r1=nums1[cnt1];
            if(cnt2!=0) l2=nums2[cnt2-1];
            if(cnt2!=m) r2=nums2[cnt2];
            if(l1<=r2 && l2<=r1){
                if((n+m)%2==0) return (max(l1,l2)+min(r1,r2))/2.0;
                else return max(l1,l2);
            }
            else if(l1>r2) hi=cnt1-1;
            else lo=cnt1+1;
        }
        return 0.0;
    }